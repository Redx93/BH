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

private:
	void WriteToDisk(std::string filepath = "file.data", bool reset = false);
	void ReadFromDisk(std::string filepath = "file.data");
	std::map<std::string, float> SaveInteger;
	std::map<std::string, std::string> SaveString;
};

