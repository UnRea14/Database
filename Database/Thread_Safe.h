#pragma once
#include "File.h"
#include <mutex>

class Thread_Safe : public File
{
	private:
		std::mutex mtx;
		int num_of_reader_threads;
	public:
		Thread_Safe();
		int Set_Value(std::string key, std::string value);
		std::string Get_Value(std::string key);
		std::string Delete_Value(std::string key);
};