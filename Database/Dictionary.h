#pragma once
#include <map>
#include <string>

class Dictionary
{
private:
	std::map<int, int> dict;
public:
	Dictionary();
	void Insert(int key, int value);
	int Set_Value(int key, int value);
	int Get_Value(int key);
	int Delete_Value(int key);
};


