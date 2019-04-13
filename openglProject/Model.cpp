#include "Model.h"



Model::Model(std::string name)
{
	m_objPath = name;
}


Model::~Model()
{
}

void Model::init(TextureManager* texManager)
{

	std::vector<glm::vec4> verticesPos;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;
	std::vector<Face> faces;

	std::ifstream in(ASSET_PATH + m_objPath);
	std::string line;
	std::string name;
	Material* material = nullptr;
	while (std::getline(in, line)) {
		std::string first;
		std::istringstream s(line);
		s >> first;
		if (first == "o") {
			s >> name;
		}
		if (first == "v") {
			//This is a vertex
			glm::vec4 vertex;
			s >> vertex.x; s >> vertex.y; s >> vertex.z;
			if (!s.eof()) {
				s >> vertex.w;
			}
			else {
				vertex.w = 1.0;
			}
			verticesPos.push_back(vertex);
		}
		else if (first == "vn") {
			//This is a normal
			glm::vec3 vertex;
			s >> vertex.x; s >> vertex.y; s >> vertex.z;
			normals.push_back(vertex);
		}
		else if (first == "vt") {
			//This is a texture coord
			glm::vec2 vertex;
			s >> vertex.x; s >> vertex.y;
			texCoords.push_back(vertex);
		}
		else if (first == "f") {
			Face face = Face(line);
			faces.push_back(face);
		}
		else if (first == "mtllib") {
			std::string path;
			s >> path;
			m_materialMap = parseMtl(path, texManager);
		}
		else if (first == "usemtl") {
			std::string materialName;
			s >> materialName;
			material = findMaterial(materialName);
		}
	}
	in.close();

	std::vector<FaceTuple> tuples;
	for (int i = 0; i < faces.size(); i++) {
		std::vector<FaceTuple> ind = faces.at(i).getTuples();
		tuples.insert(tuples.end(), ind.begin(), ind.end());
	}

	std::vector<FaceTuple> uniqueTuples;
	std::vector<unsigned int> indices;
	unsigned int indexCount = 0;

	for (int i = 0; i < tuples.size(); i++) {
		FaceTuple t = tuples.at(i);
		bool add = true;
		for (int j = 0; j < uniqueTuples.size(); j++) {
			if (t == uniqueTuples.at(j)) {
				add = false;
				indices.push_back(j);
				break;
			}
		}
		if (add) {
			indices.push_back(indexCount);
			uniqueTuples.push_back(t);
			indexCount++;
		}
	}

	//Change touples to vertices
	std::vector<Vertex> vertices;
	for (int i = 0; i < uniqueTuples.size(); i++) {
		FaceTuple t = uniqueTuples.at(i);
		Vertex v;
		if (t.normalIndex != -1) {
			v.normal = normals.at(t.normalIndex);
		}
		else {
			v.normal = glm::vec3();
		}
		if (t.positionIndex != -1) {
			v.position = verticesPos.at(t.positionIndex);
		}
		else {
			v.position = glm::vec4();
		}
		if (t.textureIndex != -1) {
			v.texCoord = texCoords.at(t.textureIndex);
		}
		else {
			v.texCoord = glm::vec2(-1, -1);
		}
		vertices.push_back(v);
	}

	//Default tex coordinates
	for (int i = 0; i < indices.size(); i++) {
		Vertex& v = vertices.at(indices.at(i));
		if (v.texCoord == glm::vec2(-1, -1)) {
			if (i % 3 == 0) {
				v.texCoord = glm::vec2(0.0, 0.0);
			}
			else if (i % 3 == 1) {
				v.texCoord = glm::vec2(1.0, 0.0);
			}
			else if (i % 3 == 2) {
				v.texCoord = glm::vec2(0.0, 1.0);
			}
		}
	}

	Mesh mesh(name, vertices, indices, material);
	mesh.init();
	m_meshes.push_back(mesh);
}

void Model::draw(Program* p)
{
	for (int i = 0; i < m_meshes.size(); i++) {
		m_meshes.at(i).draw(p);
	}
}

std::string Model::getPath()
{
	return m_objPath;
}

std::vector<Material*> Model::parseMtl(std::string path, TextureManager* texManager)
{
	std::vector<Material*> result;
	std::ifstream in(ASSET_PATH + path);
	std::string line;
	Material* material = nullptr;
	while (std::getline(in, line)) {
		std::istringstream stream(line);
		std::string first;
		stream >> first;
		if (first == "newmtl") {
			if (material != nullptr) {
				result.push_back(material);
			}
			material = new Material();
			material->name = line.substr(7);
		}
		else if (first == "Ka") {
			glm::vec3 ambient;
			stream >> ambient.x; stream >> ambient.y; stream >> ambient.z;
			material->ambientColor = ambient;
		}
		else if (first == "Kd") {
			glm::vec3 diffuse;
			stream >> diffuse.x; stream >> diffuse.y; stream >> diffuse.z;
			material->diffuseColor = diffuse;
		}
		else if (first == "Ks") {
			glm::vec3 specular;
			stream >> specular.x; stream >> specular.y; stream >> specular.z;
			material->specularColor = specular;
		}
		else if (first == "Ns") {
			stream >> material->shininess;
		}
		else if (first == "map_Ka") {
			std::string path;
			stream >> path;
			material->ambientMap = texManager->getTexture(path);
		}
		else if (first == "map_Kd") {
			std::string path;
			stream >> path;
			material->diffuseMap = texManager->getTexture(path);
		}
		else if (first == "map_Ks") {
			std::string path;
			stream >> path;
			material->specularMap = texManager->getTexture(path);
		}
		else if (first == "map_Ns") {
		}
	}
	if (material != nullptr) {
		result.push_back(material);
	}
	return result;
}

Material * Model::findMaterial(std::string name)
{
	for (int i = 0; i < m_materialMap.size(); i++) {
		if (name == m_materialMap.at(i)->name) {
			return m_materialMap.at(i);
		}
	}
	return nullptr;
}
