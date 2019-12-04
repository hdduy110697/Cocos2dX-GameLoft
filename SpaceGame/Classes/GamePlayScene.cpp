#include "GamePlayScene.h"

Scene* GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

bool GamePlayScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	return true;
}

void GamePlayScene::update(FLOAT deltaTime)
{
}

void GamePlayScene::GenerateRock()
{
}
