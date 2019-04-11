#include "Model.h"



Model::Model(std::string name)
{
	m_objPath = name;
}


Model::~Model()
{
}

void Model::init()
{
	std::vector<glm::vec4> verticesPos;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;
	std::vector<Face> faces;

	std::ifstream in(ASSET_PATH + m_objPath);
	std::string line;
	while (std::getline(in, line)) {
		std::string first;
		std::istringstream s(line);
		s >> first;
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
			//Do something with mtllib here
			std::string path;
			s >> path;
			m_materialMap = MtlParser::parse(path);
		}
	}

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
			v.texCoord = glm::vec2();
		}
		vertices.push_back(v);
	}

	Mesh mesh(vertices, indices);
	mesh.init();
	m_meshes.push_back(mesh);
}

void Model::draw()
{
	for (int i = 0; i < m_meshes.size(); i++) {
		m_meshes.at(i).draw();
	}
}

std::string Model::getPath()
{
	return m_objPath;
}
