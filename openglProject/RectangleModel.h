#pragma once

#include "Model.h"

class RectangleModel : public Model
{
public:
	RectangleModel(float width, float height, Material* m);
	~RectangleModel();

	// Inherited via Model
	virtual void draw(Program * p) override;

	// Inherited via Model
	virtual bool operator==(Model * another) override;

	// Inherited via Model
	virtual void init() override;
private:
	float m_width;
	float m_height;
	Material* m_material;
};

