#include "File.h"
#include "Dictionary.h"
#include <iostream>
#include <string>
#include <fstream>

File::File()
{//Creates the file
	this->name = "Database.txt";
	this->file.open(this->name);
	if (!file.is_open()) {
		std::cerr << "failed! maybe there is already a file with the name 'Database' ?" << std::endl;
	}
	else {
		std::cout << "file " << this->name << " is created!" << std::endl;
		file.close();
	}
}

int File:: Write()
{//Writes to the file
	this->file.open(this->name, std::ios::out);
	if (!file.is_open()) {
		std::cerr << "failed!" << std::endl;
	}
	else {
		file.close();
	}
	return 0;
}

int File::Read()
{//Reads from file
	this->file.open(this->name, std::ios::in);
	if (!file.is_open()) {
		std::cerr << "failed!" << std::endl;
	}
	else {
		file.close();
	}
	return 0;
}

bool File::Is_Currently_Used()
{//Returns true if file is currently in use, false else
	if (this->file.is_open()) {
		return true;
	}
	return false;
}
