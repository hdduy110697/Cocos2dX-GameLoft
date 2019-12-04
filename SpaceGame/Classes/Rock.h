#pragma once
#include "Object.h"
class Rock :
	public Object
{
	Rock(cocos2d::Scene* scene);
	~Rock();
	void Init();
	void Update(float deltaTime);
};