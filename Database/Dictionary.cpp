#include "Dictionary.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

Dictionary::Dictionary() 
{//
	this->dict = {};
}
void Dictionary::Insert(int key, int value)
{// inserts a pair with given key, value to the dictionary
	this->dict.insert(std::pair<int, int>(key, value));
}
int Dictionary::Set_Value(int key, int value)
{// sets the value of the given key to the given value and returns 1 if successfull, 0 otherwise
	if (this->dict.find(key) != this->dict.end()) {
		this->dict[key] = value;
		return 1;
	}
	return 0;
}
int Dictionary::Get_Value(int key)
{//returns the value int the dictionary with the given key
	return (this->dict.find(key) != this->dict.end()) ? this->dict.find(key)->second: 0;
}
int Dictionary::Delete_Value(int key)
{// deletes a value with the given key from the dictionary and returns it if successfull, 0 otherwise
	if (this->dict.find(key) != this->dict.end()) {
		int value = this->dict.find(key)->second;
		this->dict.erase(key);
		return value;
	}
	return 0;
}
void Dictionary::Print()
{// prints the dictionary
	string s = "{";
	for (auto i = this->dict.begin(); i != this->dict.end(); i++) {
		s += "(" + to_string(i->first) + "->" + to_string(i->second) + ")";
	}
	s += "}";
	cout << s << endl;
}
