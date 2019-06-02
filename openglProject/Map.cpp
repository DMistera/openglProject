#include "Map.h"



Map::Map()
{
}

Chamber * Map::getActiveChamber()
{
	return m_activeChamber;
}

void Map::generate(ResourceManager* manager, Camera* camera)
{
	m_entities = std::vector<Entity*>(maxX*maxZ);
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxZ; y++) {
			Chamber* chamber = new Chamber(manager, camera, x, y);
			addChamber(chamber);
		}
	}
	for (Entity* e : m_entities) {
		setChamberAdjacents(dynamic_cast<Chamber*>(e));
	}
	generateMaze();
	for (Entity* e : m_entities) {
		dynamic_cast<Chamber*>(e)->generateHitbox();
	}
	m_activeChamber = dynamic_cast<Chamber*>(m_entities[0]);
}




Chamber * Map::getChamber(int x, int z)
{
	if (x < 0 || x >= maxX) {
		return nullptr;
	}
	if (z < 0 || z >= maxZ) {
		return nullptr;
	}
	return dynamic_cast<Chamber*>( m_entities[linearise(x, z)]);
}

void Map::addChamber(Chamber * c)
{
	m_entities[linearise(c->getX(), c->getZ())] = c;
}



void Map::setChamberAdjacents(Chamber * c)
{
	int x = c->getX();
	int z = c->getZ();
	Chamber* c1 = getChamber(x + 1, z);
	Chamber* c2 = getChamber(x - 1, z);
	Chamber* c3 = getChamber(x, z + 1);
	Chamber* c4 = getChamber(x, z - 1);
	if (c1 != nullptr) {
		c->addAdjacentChamber(c1);
	}
	if (c2 != nullptr) {
		c->addAdjacentChamber(c2);
	}
	if (c3 != nullptr) {
		c->addAdjacentChamber(c3);
	}
	if (c4 != nullptr) {
		c->addAdjacentChamber(c4);
	}
}

void Map::checkActiveChamberChange(Player * p)
{
	for (Chamber* c : m_activeChamber->getAdjacentChambers()) {
		//if (p->getHitbox()->collide(c->getDoorFrameHitboxes())) {
		if (c->getDoorFrameHitbox()->isPointInside(p->getHitbox()->getGlobalPosition() + glm::vec3(0.0f, 0.5f, 0.0f))) {
			m_activeChamber = c;
		}
	}
}




Map::~Map()
{
}

void Map::generateMaze()
{
	//Using depth first
	struct Node {
		bool visited = false;
		Chamber* chamber;
	};
	std::vector<Node*> nodes(m_entities.size());
	for (int x = 0; x < maxX; x++) {
		for (int z = 0; z < maxZ; z++) {
			Node* n = new Node();
			nodes[linearise(x, z)] = n;
			Chamber* c = getChamber(x, z);
			n->chamber = c;
		}
	}

	std::srand(unsigned(std::time(0)));

	auto getNode = [&](int x, int z) -> Node* {
		if (x < 0 || x >= maxX) {
			return nullptr;
		}
		if (z < 0 || z >= maxZ) {
			return nullptr;
		}
		return nodes[linearise(x, z)];
	};

	Node* first = getNode(0, 0);

	std::function<void(Node*)> f = [&](Node* currentNode) -> void {
		std::vector<int> v;
		for (int i = 0; i < 4; ++i) v.push_back(i); // 1 2 3 4
		std::random_shuffle(v.begin(), v.end());

		int x = currentNode->chamber->getX();
		int z = currentNode->chamber->getZ();

		for (int i : v) {
			Node* n = nullptr;
			if (i == 0) {
				n = getNode(x + 1, z);
			}
			else if(i == 1) {
				n = getNode(x - 1, z);
			}
			else if (i == 2) {
				n = getNode(x, z + 1);
			}
			else if (i == 3) {
				n = getNode(x, z - 1);
			}

			if (n == nullptr) continue;
			if (n->visited) continue;

			//Open doors here
			if (i == 0) {
				currentNode->chamber->open(ChamberWall::Position::RIGHT);
				n->chamber->open(ChamberWall::Position::LEFT);
			}
			else if (i == 1) {
				currentNode->chamber->open(ChamberWall::Position::LEFT);
				n->chamber->open(ChamberWall::Position::RIGHT);
			}
			else if (i == 2) {
				currentNode->chamber->open(ChamberWall::Position::BOTTOM);
				n->chamber->open(ChamberWall::Position::TOP);
			}
			else if (i == 3) {
				currentNode->chamber->open(ChamberWall::Position::TOP);
				n->chamber->open(ChamberWall::Position::BOTTOM);
			}
			n->visited = true;
			f(n);
		}
	};

	f(first);
	for (Node* n : nodes) {
		delete n;
	}
	nodes.clear();
}

int Map::linearise(int x, int y)
{
	return x * maxX + y;
}
