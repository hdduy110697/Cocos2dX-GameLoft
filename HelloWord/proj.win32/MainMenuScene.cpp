#include "MainMenuScene.h"

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
	// create menu by single menu item
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	closeItem->setPosition(120, 0);
	auto label = Label::create("MENU", "Arial", 30);
	auto endItem = MenuItemLabel::create(label, nullptr);
	endItem->setPosition(30, 0);
	auto myMenu = Menu::create(closeItem, endItem, nullptr);
	myMenu->setPosition(200, 200);
	addChild(myMenu);

	// create menu by aray menu itom
	auto itemPlay = MenuItemFont::create("Play", nullptr);
	auto itemExit = MenuItemFont::create("Exit", CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	itemPlay->setPosition(0, 70);
	itemExit->setPosition(0, 20);
	Vector<MenuItem*> menuItems;
	menuItems.pushBack(itemPlay);
	menuItems.pushBack(itemExit);

	auto menu = Menu::createWithArray(menuItems);
	menu->setPosition(230, 100);
	addChild(menu);

	return true;
}

void MainMenuScene::update(FLOAT deltaTime)
{
}

void MainMenuScene::menuCloseCallback(Ref* pSender)
{
	exit(0);
}


