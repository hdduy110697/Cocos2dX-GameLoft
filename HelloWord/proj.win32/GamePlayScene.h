#pragma once
#include "G:\gameLoft\Cocos2dX-GameLoft\HelloWord\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"
#include <iostream>
USING_NS_CC;
class GamePlayScene :
	public cocos2d::Scene
{
public:
	Sprite* ship;
public:
	static Scene* createScene();
	virtual bool init();
	void update(FLOAT deltaTime);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, Event* event);
	CREATE_FUNC(GamePlayScene);
};

