#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "SaveSysteam.h"
struct Item
{
	int index;
	std::string name;
	SaveSysteam* save;
	Item() :index(0) {    }
	~Item()
	{
	}
	Item(SaveSysteam& save,int index) : index(index) ,save(&save)
	{
		std::string key = "Item" + std::to_string(index) + "Name";
		name = save.GetString(key);
	}
	
	void SetName(std::string name)
	{
		this->name = name;
	}
	std::string GetName()
	{
		return name;
	}
};
struct Inventory
{
	int numberOfItems = 0;
	std::vector<Item> items;
	SaveSysteam* save;
	Inventory(SaveSysteam &save):save(&save)
	{
		numberOfItems = save.GetInteger("ItemSize");
		for (size_t i = 0; i < numberOfItems; i++)
		{
			items.push_back(Item(save,i));
		}
	}

	Item* GetItem(std::string name)
	{
		for (auto item : items)
		{
			if (item.GetName() == name)
			{
				return &item;
			}
		}
	}
	void AddItem(Item item)
	{
		this->items.push_back(item);
	}
};

struct PlayerPref
{

};