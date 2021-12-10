#pragma once
#include <string>
#include <fstream>
#include "Dictionary.h"

class File: public Dictionary
{
	private:
		std::ofstream input_file;
		std::ifstream output_file;
		std::string name;
	public:
		File();
		int Set_Value(std::string key, std::string value);
		std::string Get_Value(std::string key);
		std::string Delete_Value(std::string key);
};