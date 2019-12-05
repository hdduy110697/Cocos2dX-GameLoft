#pragma once
#include "Object.h"
class Bullet :
	public ::Object
{
	Bullet(cocos2d::Scene* scene);
	~Bullet();
	void Init();
	void Update(float deltaTime);
};

