#include "Dictionary.h"
#include <iostream>
#include <map>
#include <string>

Dictionary::Dictionary() 
{//resets the dictionary
	this->dict = {};
}

int Dictionary::Set_Value(std::string key, std::string value)
{// sets the value of the given key to the given value and returns 1 if successful, 0 otherwise
	if (this->dict.find(key) != this->dict.end()) {
		this->dict[key] = value;
		return 1;
	}
	else if(this->dict.find(key) == this->dict.end()){
		this->dict.insert(std::make_pair(key, value));
		return 1;
	}
	return 0;
}

std::string Dictionary::Get_Value(std::string key)
{//returns the value in the dictionary with the given key
	return (this->dict.find(key) != this->dict.end()) ? this->dict[key]: "";
}

std::string Dictionary::Delete_Value(std::string key)
{// deletes a value with the given key from the dictionary and returns the value if successful, 0 otherwise
	if (this->dict.find(key) != this->dict.end()) {
		std::string value = this->dict[key];
		this->dict.erase(key);
		return value;
	}
	return 0;
}
