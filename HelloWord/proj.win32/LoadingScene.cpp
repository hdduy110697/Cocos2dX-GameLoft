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
	scheduleUpdate();
	//get spire
	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("Sprites/SpaceShip/ship.plist");
	auto spriteFrame = spriteCache->getSpriteFrameByName("1.png");
	ship = Sprite::createWithSpriteFrame(spriteFrame);
	ship->setPosition(50, 50);
	addChild(ship);
	//move to


	Vector<SpriteFrame*> animFrames;
	animFrames.pushBack(spriteCache->getSpriteFrameByName("1.png"));
	animFrames.pushBack(spriteCache->getSpriteFrameByName("2.png"));
	animFrames.pushBack(spriteCache->getSpriteFrameByName("3.png"));
	animFrames.pushBack(spriteCache->getSpriteFrameByName("4.png"));
	animFrames.pushBack(spriteCache->getSpriteFrameByName("5.png"));
	animFrames.pushBack(spriteCache->getSpriteFrameByName("6.png"));
	animFrames.pushBack(spriteCache->getSpriteFrameByName("7.png"));

	//animation
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);

	//ship animation
	ship->runAction(RepeatForever::create(animate));

	return true;
}

void LoadingScene::update(FLOAT deltaTime)
{
}
