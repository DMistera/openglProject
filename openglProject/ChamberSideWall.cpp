#include "ChamberSideWall.h"

const float ChamberSideWall::DOOR_WIDTH = SIZE * 1.0f / 5.0f;
const float ChamberSideWall::DOOR_HEIGHT = SIZE * 2.0f / 5.0f;

ChamberSideWall::ChamberSideWall(ResourceManager* manager, ChamberWall::Position position) : ChamberWall(manager, position)
{
	float dx = (SIZE + ChamberWall::THICKNESS) / 2.0f;
	if (position == FRONT) {
		setPosition(glm::vec3(0.0f, 0.0f, -dx));
		setRotationY(M_PI);
	}
	else if (position == BACK) {
		setPosition(glm::vec3(0.0f, 0.0f, dx));
		setRotationY(0.0f);
	}
	else if (position == LEFT) {
		setPosition(glm::vec3(-dx, 0.0f, 0.0f));
		setRotationY(M_PI*(1.5f));
	}
	else if (position == RIGHT) {
		setPosition(glm::vec3(dx, 0.0f, 0.0f));
		setRotationY(M_PI*(0.5f));
	}
}


ChamberSideWall::~ChamberSideWall()
{
}

ModelFromFile * ChamberSideWall::getModelWhenClosed()
{
	return m_resourceManagerP->getModel("ClosedWall.obj");
}

ModelFromFile * ChamberSideWall::getModelWhenOpen()
{
	return m_resourceManagerP->getModel("OpenWall.obj");
}

Hitbox * ChamberSideWall::getHitboxWhenOpen()
{
	HitboxGroup* result = new HitboxGroup();
	float leftX = -DOOR_WIDTH / 2.0f;
	float rightX = DOOR_WIDTH / 2.0f;
	float mostLeftX = -SIZE / 2.0f;
	float mostRightX = SIZE / 2.0f;
	float wallWidth = mostRightX - rightX;
	float middleLeftX = (leftX + mostLeftX) / 2.0f;
	float middleRightX = (rightX + mostRightX) / 2.0f;
	PrismHitbox* leftWall = new PrismHitbox(new Rectangle(wallWidth, THICKNESS), 0, SIZE);
	leftWall->setPosition(glm::vec3(middleLeftX, 0.0f, 0.0f));
	PrismHitbox* rightWall = new PrismHitbox(new Rectangle(wallWidth, THICKNESS), 0, SIZE);
	rightWall->setPosition(glm::vec3(middleRightX, 0.0f, 0.0f));
	float doorFrameWallHeight = SIZE - DOOR_HEIGHT;
	PrismHitbox* doorFrameWall = new PrismHitbox(new Rectangle(DOOR_WIDTH, THICKNESS), SIZE - doorFrameWallHeight, SIZE);
	result->addHitbox(leftWall);
	result->addHitbox(rightWall);
	result->addHitbox(doorFrameWall);
	return result;
}

Hitbox * ChamberSideWall::getHitboxWhenClosed()
{
	return new PrismHitbox(new Rectangle(SIZE, ChamberWall::THICKNESS), SIZE);;
}
