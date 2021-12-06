#include "Dictionary.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

Dictionary::Dictionary() 
{//resets the dictionary
	this->dict = {};
}
void Dictionary::Insert(int key, int value)
{// inserts a pair with given key, value to the dictionary
	this->dict.insert(make_pair(key, value));
}
int Dictionary::Set_Value(int key, int value)
{// sets the value of the given key to the given value and returns 1 if successful, 0 otherwise
	if (this->dict.find(key) != this->dict.end()) {
		this->dict[key] = value;
		return 1;
	}
	return 0;
}
int Dictionary::Get_Value(int key)
{//returns the value int the dictionary with the given key
	return (this->dict.find(key) != this->dict.end()) ? this->dict[key]: 0;
}
int Dictionary::Delete_Value(int key)
{// deletes a value with the given key from the dictionary and returns the value if successful, 0 otherwise
	if (this->dict.find(key) != this->dict.end()) {
		int value = this->dict[key];
		this->dict.erase(key);
		return value;
	}
	return 0;
}
