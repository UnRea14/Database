#include "Thread_Safe.h"
#include "File.h"
#include <thread>
#include <string>

Thread_Safe::Thread_Safe()
{
	this->num_of_reader_threads = 0;
	File::File();
}

int Thread_Safe::Set_Value(std::string key, std::string value)
{
	this->mtx.try_lock;
	int returned_value = File::Set_Value(key, value);
	mtx.unlock;
	return value;
}

std::string Thread_Safe::Get_Value(std::string key)
{
	++this->num_of_reader_threads;
	if (this->num_of_reader_threads == 10) {
		this->mtx.try_lock;
		std::string returned_value = File::Get_Value(key);
		this->mtx.unlock;
		--this->num_of_reader_threads;
		return returned_value;
	}
	return File::Get_Value(key);
}

std::string Thread_Safe::Delete_Value(std::string key)
{
	this->mtx.try_lock;
	std::string returned_value = File::Delete_Value(key);
	mtx.unlock;
	return returned_value;
}
