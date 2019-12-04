#include "LoadingScene.h"

Scene* LoadingScene::createScene()
{
	return LoadingScene::create();
}

bool LoadingScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	return true;
}

void LoadingScene::update(FLOAT deltaTime)
{
}
