#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "SaveSysteam.h"
struct Item
{
	int index;
	std::string name;
	Item() :index(0) {    }
	~Item() {	}
	Item(int index) : index(index)
	{
		this->index = index;
		load();
	}
	Item(const Item& other)
	{
		this->name = other.name;
		this->index = other.index;
	}

	void SetName(std::string name)
	{
		this->name = name;
	}
	std::string GetName()
	{
		return name;
	}
	void Save()
	{
		SaveSysteam* ss = SaveSysteam::GetInstance();
		std::string key = "Item" + std::to_string(index) + "Name";
		ss->Set(key, name);
	}
	void load()
	{
		SaveSysteam* ss = SaveSysteam::GetInstance();
		std::string key = "Item" + std::to_string(index) + "Name";
		name = ss->GetString(key);
	}
};
struct Inventory
{
	std::vector<Item> items;
	Inventory()
	{
		load();
	}
	Inventory(const Inventory& other)
	{
		this->items = other.items;
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
	void AddItem(Item& item)
	{
		bool found = false;
		for (size_t i = 0; i < items.size() &&!found; i++)
		{
			if (items[i].name == item.name)
			{
				found = true;
			}
		}
		if (!found)
		{
			this->items.push_back(item);
		}
	}
	void Save()
	{
		SaveSysteam* ss = SaveSysteam::GetInstance();
		int numberOfItems = items.size();
		ss->Set("ItemSize", numberOfItems);

		for (auto item : items)
		{
			item.Save();
		}
	}
	void load()
	{
		SaveSysteam* ss = SaveSysteam::GetInstance();
		int numberOfItems = ss->GetInteger("ItemSize");
		for (size_t i = 0; i < numberOfItems; i++)
		{
			items.push_back(Item(i));
		}
	}
};

struct PlayerPref
{

};