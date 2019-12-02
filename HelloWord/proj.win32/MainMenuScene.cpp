#include "MainMenuScene.h"
#include <cocos\ui\UICheckBox.h>
#include <cocos\ui\UISlider.h>
#include <cocos\ui\UIScrollView.h>
#include <cocos\ui\UITextField.h>

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
	auto itemSound = MenuItemFont::create("Sound", CC_CALLBACK_1(MainMenuScene::soundCallback, this));
	auto itemAbout = MenuItemFont::create("About", CC_CALLBACK_1(MainMenuScene::aboutCallback, this));
	auto itemNamePlayer = MenuItemFont::create("Change Name Player", CC_CALLBACK_1(MainMenuScene::editNamePlayerCallback, this));
	auto itemExit = MenuItemFont::create("Exit", CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	itemPlay->setPosition(0, 70);
	itemSound->setPosition(0, 20);
	itemNamePlayer->setPosition(0, -30);
	itemExit->setPosition(0, -80);
	Vector<MenuItem*> menuItems;
	menuItems.pushBack(itemPlay);
	menuItems.pushBack(itemSound);
	menuItems.pushBack(itemAbout);
	menuItems.pushBack(itemNamePlayer);
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
void MainMenuScene::soundCallback(Ref* pSender)
{
	auto checkbox = ui::CheckBox::create("Sprites/checkbox_normal.png",
		"Sprites/checkbox_pressed.png",
		"Sprites/checkbox_checked.png",
		"Sprites/checkbox_normal_disable.png",
		"Sprites/checkbox_checked_disable.png");
	checkbox->setPosition(Vec2(340,100));
	checkbox->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
		{
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				log("checkbox 1 clicked");
				break;
			default:
				break;
			}
		});
	this->addChild(checkbox);
	// Slider
	static auto slider = ui::Slider::create();
	slider->loadBarTexture("Sprites/slider_bar_bg.png");
	slider->loadSlidBallTextures("Sprites/slider_ball_normal.png", "Sprites/slider_ball_pressed.png", "Sprites/slider_ball_disable.png");
	slider->loadProgressBarTexture("Sprites/slider_bar_pressed.png");
	slider->setPercent(10);
	slider->setPosition(Vec2(340, 50));
	slider->addClickEventListener([](Ref* event) {
		log("Slider: %d", slider->getPercent());
		});
	addChild(slider);


}

void MainMenuScene::aboutCallback(Ref* pSender)
{
	auto scrollView = ui::ScrollView::create();
	scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	scrollView->setContentSize(Size(200, 200));
	scrollView->setInnerContainerSize(Size(10, 1000));
	scrollView->setBounceEnabled(true);
	scrollView->setPosition(Vec2(50, 50));
	for (int i = 0; i < 50; i++)
	{
		if (i < 10) {
			auto label = Label::createWithSystemFont("nice game ", "Arial", 20);
			label->setPosition(Vec2(scrollView->getContentSize().width / 2, i * 30));
			scrollView->addChild(label);
		}
		else
		{
			auto label = Label::createWithSystemFont("bad game ", "Arial", 20);
			label->setPosition(Vec2(scrollView->getContentSize().width / 2, i * 30));
			scrollView->addChild(label);
		}
		
	}
	addChild(scrollView);

}

void MainMenuScene::editNamePlayerCallback(Ref* pSender)
{
	static auto textField = ui::TextField::create("NinNinNin", "Arial", 30);
	textField->setMaxLengthEnabled(true);
	textField->setMaxLength(10);
	textField->setPasswordEnabled(true);
	textField->setPosition(Vec2(400, 200));
	textField->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
		{
			log("editing a TextField");
		});
	addChild(textField);

}


