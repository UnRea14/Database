#include <iostream>
#include "Dictionary.h"
using namespace std;

int main()
{
	Dictionary dict;
	dict.Insert(1, 10);
	dict.Insert(2, 20);
	dict.Insert(3, 30);
	cout << dict.Get_Value(2) << endl;
	cout << dict.Delete_Value(2) << endl;
}
