#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

ResourceManager* ResourceManager::GetInstance()
{
	return this;
}

void ResourceManager::Init(const string path)
{
}

void ResourceManager::Load(string fileName)
{
}

Sprite* ResourceManager::GetSpriteById(char id)
{
	return nullptr;
}

ui::Button* ResourceManager::GetButtonById(char id)
{
	return nullptr;
}

Label* ResourceManager::GetLabelById(char id)
{
	return nullptr;
}
