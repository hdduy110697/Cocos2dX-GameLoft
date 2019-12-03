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
	scheduleUpdate();
	//get spire and animation
	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("Sprites/SpaceShip/ship.plist");
	auto spriteFrame = spriteCache->getSpriteFrameByName("1.png");
	ship = Sprite::createWithSpriteFrame(spriteFrame);
	ship->setPosition(50, 50);
	addChild(ship);
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
	// end animation
	//sign touch
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GamePlayScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GamePlayScene::onTouchEnded, this);
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(GamePlayScene::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(GamePlayScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	return true;
}
bool GamePlayScene::onTouchBegan(Touch* touch, Event* event)
{
	Vec2 shipPos = touch->getLocation();
	auto moveTo = MoveTo::create(1.0f, shipPos);
	ship->runAction(moveTo);
	return true;
}
void GamePlayScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	auto moveBy = MoveBy::create(1.0f, Vec2(0, 0));
	auto repeatForever = cocos2d::RepeatForever::create(moveBy);

	if (keyCode== EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		moveBy = MoveBy::create(1.0f, Vec2(-100, 0));
		repeatForever = cocos2d::RepeatForever::create(moveBy);
		repeatForever->setTag(999);
		ship->runAction(repeatForever);
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		moveBy = MoveBy::create(1.0f, Vec2(100, 0));
		repeatForever = cocos2d::RepeatForever::create(moveBy);
		repeatForever->setTag(999);
		ship->runAction(repeatForever);
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		moveBy = MoveBy::create(1.0f, Vec2(0, 100));
		repeatForever = cocos2d::RepeatForever::create(moveBy);
		repeatForever->setTag(999);
		ship->runAction(repeatForever);
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		moveBy = MoveBy::create(1.0f, Vec2(0, -100));
		repeatForever = cocos2d::RepeatForever::create(moveBy);
		repeatForever->setTag(999);
		ship->runAction(repeatForever);
	}
	
}
void GamePlayScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	ship->stopActionByTag(999);
	
}
void GamePlayScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

void GamePlayScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
}


void GamePlayScene::update(FLOAT deltaTime)
{
}
