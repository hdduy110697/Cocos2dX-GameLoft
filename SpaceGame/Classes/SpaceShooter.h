#pragma once
#include "Object.h"
#include "Rock.h"
#include <list>
#include <vector> 
class SpaceShooter :
	public ::Object
{
public:
	std::list<Object*> m_bullet;
public:
	SpaceShooter(cocos2d::Scene* scene);
	~SpaceShooter();
	void Init();
	void Update(float deltaTime);
	void Shoot();
	void Collision(std::vector<Rock*>);
};

