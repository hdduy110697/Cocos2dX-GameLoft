#include "LogoScene.h"
#include "HelloWorldScene.h"
#include <proj.win32\LoadingScene.h>
#include <proj.win32\MainMenuScene.h>
Scene* LogoScene::createScene()
{
	return LogoScene::create();
}

bool LogoScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	scheduleUpdate();


	auto bee = Sprite::create("Sprites/bee1.png");
	bee->setPosition(30, 100);
	addChild(bee);

	//Tạo các hiệu cho bee từ 3 sprite, dùng đối tượng SpriteFrame
	Vector<SpriteFrame*> animFrames;
	animFrames.pushBack(SpriteFrame::create("Sprites/bee1.png", Rect(0, 0, 150, 150)));
	animFrames.pushBack(SpriteFrame::create("Sprites/bee2.png", Rect(0, 0, 150, 150)));
	animFrames.pushBack(SpriteFrame::create("Sprites/bee3.png", Rect(0, 0, 150, 150)));

	//Tạo hình ảnh động
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);

	//Gắn hình ảnh động cho bee và chạy nó lặp vô hạn
	bee->runAction(RepeatForever::create(animate));

	
	
	//move by
	auto moveBy = MoveBy::create(2, Vec2(50, 0));
	bee->runAction(moveBy);
	////ease Move To
	//auto move_ease_in = EaseBounceIn::create(moveTo->clone());
	//auto move_ease_in_back = move_ease_in->reverse();
	////ease Move To Elasticout
	auto move_ease_moveBy_in = EaseElasticOut::create(moveBy);
	auto move_ease_in_moveBy_back = move_ease_moveBy_in->reverse();
	auto delay = DelayTime::create(0.25f);


	auto seq = Sequence::create(move_ease_moveBy_in, delay, move_ease_in_moveBy_back, delay->clone(), nullptr);
	bee->runAction(RepeatForever::create(seq));
	return true;
}

float a = 0;
void LogoScene::update(FLOAT deltaTime)
{
	a=a+deltaTime;
	if (a >= 3) {
		auto scene = MainMenuScene::createScene();
		Director::getInstance()->replaceScene(scene);
	}


}


