#include "Instancer.h"



Instancer::Instancer(Entity* entity)
{
	m_entity = entity;

}


Instancer::~Instancer()
{
}

void Instancer::draw()
{
	if (m_outdated) {
		updateInstanceGroups();
	}
	for (InstanceGroup g : m_instanceGroups) {
		g.getProgram()->use();
		setUniforms(g.getSample());
		g.getMesh()->use(g.getProgram());
		g.getMesh()->bind();
		setInstancedVertexAttributes(g.getEntities());
		glDrawElementsInstanced(GL_TRIANGLES, g.getMesh()->getIndices()->size(), GL_UNSIGNED_INT, 0, g.getEntities().size());
		cleanUp();
		g.getMesh()->unbind();
	}
}

void Instancer::init()
{
	updateInstanceGroups();
	m_entity->setChildrenUpdateCallback([&]() -> void {
		m_outdated = true;
	});
}

void Instancer::updateInstanceGroups()
{
	auto merge = [&](std::vector<InstanceGroup>* original, std::vector<InstanceGroup>* additional) -> void {
		for (InstanceGroup& a : *additional) {
			bool found = false;
			for (InstanceGroup& o : *original) {
				if (inSameInstanceGroup(o.getSample(), a.getSample())
					&& (*a.getMesh()) == o.getMesh()
					&& (*a.getProgram()) == (*o.getProgram())) {
					o.addEntities(a.getEntities());
					found = true;
				}
			}
			if (!found) {
				original->push_back(a);
			}
		}
	};
	std::function<std::vector<InstanceGroup>(Entity* entity)> f = [&](Entity* entity) -> std::vector<InstanceGroup> {
		std::vector<InstanceGroup> result;
		//Get instanced groups from children
		for (Entity* e : entity->getEntities()) {
			merge(&result, &f(e));
		}
		if (entity->isDrawable()) {
			//Get instanced groups from model
			std::vector<InstanceGroup> modelInstances;
			std::vector<Mesh*> meshes = entity->getModel()->getMeshes();
			for (Mesh* mesh : meshes) {
				InstanceGroup instanceGroup(mesh, entity->getProgram());
				instanceGroup.addEntity(entity);
				modelInstances.push_back(instanceGroup);
			}
			merge(&result, &modelInstances);
		}
		return result;
	};

	m_instanceGroups = f(m_entity);
	m_outdated = false;
}
