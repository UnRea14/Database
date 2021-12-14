#include "File.h"
#include <iostream>
#include <string>
#include <fstream>

File::File()
{//Creates the file
	Dictionary::Dictionary();
	this->name = "Database.txt";
	this->input_file.open(this->name);
	if (!this->input_file.is_open()) {
		std::cerr << "failed!" << std::endl;
	}
	else {
		std::cout << "file " << this->name << " is opened!" << std::endl;
		this->input_file.close();
	}
}

int File::Set_Value(std::string key, std::string value)
{//Writes to the file. returns 1 if successfull, 0 else
	int returned = Dictionary::Set_Value(key, value);
	if (returned != 0) {
		this->input_file.open(this->name, std::ios::app);
		if (this->input_file.is_open()) {
			std::string value = Dictionary::Get_Value(key);
			this->input_file << value << std::endl;
			this->input_file.close();
			return 1;
		}
	}
	return 0;
}

std::string File::Get_Value(std::string key)
{//Reads from file
	return Dictionary::Get_Value(key);
}

std::string File::Delete_Value(std::string key)
{
	std::string value = "";
	this->output_file.open(this->name);
	if (this->output_file.is_open()) {
		std::string temp_file_name = "temp.txt", line;
		value = Dictionary::Get_Value(key);
		std::ofstream temp_file;
		temp_file.open(temp_file_name);
		if (temp_file.is_open()) {
			while (getline(this->output_file, line)) {
				if (line != value) {
					temp_file << line << std::endl;
				}
			}
			temp_file.close();
			this->output_file.close();
			remove(this->name.c_str());
			int returned = rename(temp_file_name.c_str(), this->name.c_str());
			if (returned != 0) {
				std::cerr << "Error in renaming the file" << std::endl;
			}
		}
	}
	return value;
}