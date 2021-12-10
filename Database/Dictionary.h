#pragma once
#include <map>
#include <string>

class Dictionary
{
private:
	std::map<std::string, std::string> dict;
public:
	Dictionary();
	virtual int Set_Value(std::string key, std::string value);
	virtual std::string Get_Value(std::string key);
	virtual std::string Delete_Value(std::string key);
};