#include "LogoScene.h"
#include "HelloWorldScene.h"
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
	return true;
}

int a = 0;
void LogoScene::update(FLOAT deltaTime)
{
	 a++;
	if (a==(10))
	{
		auto myScene = HelloWorld::createScene();
		auto SceneTemp= TransitionFade::create(0.5, myScene, Color3B(0, 255, 255));
		Director::getInstance()->replaceScene(SceneTemp);

	}

}


