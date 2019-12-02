#pragma once
#include <iostream>
#include <map>
class SaveSysteam
{
public:
	SaveSysteam();
	~SaveSysteam();

	void Set(std::string key, float value);
	void Set(std::string key, std::string value);

	std::string GetString(std::string key);
	float GetInteger(std::string key);

	static SaveSysteam* GetInstance();
private:
	void save(std::string filepath = "file.data", bool reset = false);
	void read(std::string filepath = "file.data");
	std::map<std::string, float> SaveInteger;
	std::map<std::string, std::string> SaveString;

	static SaveSysteam* saveData;
};


