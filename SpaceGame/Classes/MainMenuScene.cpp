#include "MainMenuScene.h"
#include <cocos\ui\UIButton.h>
#include <ResourceManager.h>

Scene* MainMenuScene::createScene()
{
	return MainMenuScene::create();
}

bool MainMenuScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	std::string s = "Data.bin";
	ResourceManager* resource = new ResourceManager();
	resource->Init(s);
	auto playButton  = resource->GetButtonById(1);
	playButton->setPosition(Vec2(160, 240));
	playButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			break;
		default:
			break;
		}
		});
	addChild(playButton);

	;
	return true;

}
