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
	m_entities = std::vector<Entity*>(maxX*maxZ*maxY);
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			for (int z = 0; z < maxZ; z++) {
				Chamber* chamber = new Chamber(manager, camera, x, y, z);
				addChamber(chamber);
			}
		}
	}
	for (Entity* e : m_entities) {
		setChamberAdjacents(dynamic_cast<Chamber*>(e));
	}
	generateMaze();
	for (Entity* e : m_entities) {
		Chamber* c = dynamic_cast<Chamber*>(e);
		c->generateHitbox();
		c->fill(manager, camera);
	}
	m_activeChamber = dynamic_cast<Chamber*>(m_entities[0]);
}




Chamber * Map::getChamber(int x, int y, int z)
{
	if (x < 0 || x >= maxX) {
		return nullptr;
	}
	if (y < 0 || y >= maxY) {
		return nullptr;
	}
	if (z < 0 || z >= maxZ) {
		return nullptr;
	}
	return dynamic_cast<Chamber*>( m_entities[linearise(x, y, z)]);
}

void Map::addChamber(Chamber * c)
{
	m_entities[linearise(c->getX(), c->getY(), c->getZ())] = c;
}



void Map::setChamberAdjacents(Chamber * c)
{
	int x = c->getX();
	int z = c->getZ();
	int y = c->getY();
	std::vector<Chamber*> adj(6);
	adj[0] = getChamber(x + 1, y, z);
	adj[1] = getChamber(x - 1, y, z);
	adj[2] = getChamber(x, y, z + 1);
	adj[3] = getChamber(x, y, z - 1);
	adj[4] = getChamber(x, y - 1, z);
	adj[5] = getChamber(x, y + 1, z);
	for (Chamber* ch : adj) {
		if (ch != nullptr) {
			c->addAdjacentChamber(ch);
		}
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

void Map::updateAll(double deltaTime)
{
	for (Entity* e : m_entities) {
		dynamic_cast<Chamber*>(e)->update(deltaTime);
	}
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
		for (int y = 0; y < maxY; y++) {
			for (int z = 0; z < maxZ; z++) {
				Node* n = new Node();
				nodes[linearise(x, y, z)] = n;
				Chamber* c = getChamber(x, y, z);
				n->chamber = c;
			}
		}
	}

	std::srand(unsigned(std::time(0)));

	auto getNode = [&](int x, int y, int z) -> Node* {
		if (x < 0 || x >= maxX) {
			return nullptr;
		}
		if (y < 0 || y >= maxY) {
			return nullptr;
		}
		if (z < 0 || z >= maxZ) {
			return nullptr;
		}
		return nodes[linearise(x, y, z)];
	};

	Node* first = getNode(0, 0, 0);

	std::function<void(Node*)> f = [&](Node* currentNode) -> void {
		std::vector<int> v;
		for (int i = 0; i < 6; i++) v.push_back(i); // 0 1 2 3 4 5
		std::random_shuffle(v.begin(), v.end());

		int x = currentNode->chamber->getX();
		int y = currentNode->chamber->getY();
		int z = currentNode->chamber->getZ();

		for (int i : v) {
			Node* n = nullptr;
			if (i == 0) {
				n = getNode(x + 1, y, z);
			}
			else if(i == 1) {
				n = getNode(x - 1, y, z);
			}
			else if (i == 2) {
				n = getNode(x, y, z + 1);
			}
			else if (i == 3) {
				n = getNode(x, y, z - 1);
			}
			else if (i == 4) {
				n = getNode(x, y - 1, z);
			}
			else if (i == 5) {
				n = getNode(x, y + 1, z);
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
				currentNode->chamber->open(ChamberWall::Position::BACK);
				n->chamber->open(ChamberWall::Position::FRONT);
			}
			else if (i == 3) {
				currentNode->chamber->open(ChamberWall::Position::FRONT);
				n->chamber->open(ChamberWall::Position::BACK);
			}
			else if (i == 4) {
				currentNode->chamber->open(ChamberWall::Position::DOWN);
				n->chamber->open(ChamberWall::Position::UP);
			}
			else if (i == 5) {
				currentNode->chamber->open(ChamberWall::Position::UP);
				n->chamber->open(ChamberWall::Position::DOWN);
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

int Map::linearise(int x, int y, int z)
{
	return z * maxX * maxY + y * maxX + x;
}
