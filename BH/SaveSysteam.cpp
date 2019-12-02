#include "SaveSysteam.h"
#include <fstream>
#include <ostream>
SaveSysteam* SaveSysteam::saveData = nullptr;

SaveSysteam::SaveSysteam()
{
	read();
	saveData = this;
}
SaveSysteam::~SaveSysteam()
{
	save();
}

void SaveSysteam::Set(std::string key, float value)
{
	if (key != "")
	{
		SaveInteger[key] = value;
	}
}
void SaveSysteam::Set(std::string key, std::string value)
{
	if (key != "" && value != "")
	{
		SaveString[key] = value;
	}
}
std::string SaveSysteam::GetString(std::string key)
{
	if (SaveString.count(key) && key != "")
	{
		return	this->SaveString.at(key);
	}
	else
	{
		return "";
	}
}
float SaveSysteam::GetInteger(std::string key)
{
	if (SaveInteger.count(key))
	{
		return	this->SaveInteger.at(key);
	}
	else
	{
		return 0;
	}
}
SaveSysteam* SaveSysteam::GetInstance()
{
	return saveData;
}
void SaveSysteam::save(std::string filepath, bool reset)
{
	std::ofstream myfile;
	myfile.open(filepath);
	myfile << SaveInteger.size() << std::endl;
	myfile << SaveString.size() << std::endl;

	/*write to disk til we have nothing else to write*/
	if (SaveString.size() > 0)
	{
		for (auto const& string : SaveString)
		{
			myfile << string.first << " " << string.second << std::endl; //first - key, second -value
		}
	}
	if (SaveInteger.size() > 0)
	{
		for (auto const& string : SaveInteger)
		{
			myfile << string.first << " " << string.second << std::endl; //first - key, second -value
		}
	}
	myfile.close();
}

void SaveSysteam::read(std::string filepath)
{
	std::ifstream myfile(filepath);
	if (myfile.is_open() && !myfile.eof())
	{
		int iValue;
		std::string	key;
		std::string sValue;
		int intergerSize;
		int stringSize;
		myfile >> intergerSize;
		myfile >> stringSize;

		for (size_t i = 0; i < stringSize; i++)
		{
			myfile >> key >> sValue;
			this->Set(key, sValue);
		}
		for (size_t i = 0; i < intergerSize; i++)
		{
			myfile >> key >> iValue;
			this->Set(key, iValue);
		}
	}
	myfile.close();
}

