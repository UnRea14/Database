#include <iostream>
#include "Dictionary.h"
#include "File.h"
using namespace std;

int main()
{
	File dict;
	dict.Set_Value("1", "10");
	dict.Set_Value("2", "20");
	dict.Set_Value("3", "100");
	cout << dict.Get_Value("2") << endl;
	cout << dict.Delete_Value("2") << endl;
}
