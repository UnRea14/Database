#pragma once
#include <string>
#include <fstream>
#include "Dictionary.h"

class File: public Dictionary
{
	private:
		std::ofstream file;
		std::string name;
	public:
		File();
		int Write();
		int Read();
		bool Is_Currently_Used();
};

