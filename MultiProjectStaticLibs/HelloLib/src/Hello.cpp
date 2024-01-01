#include "HelloLib/Hello.h"
#include "StringTransformerLib/StringTransformer.h"
#include <iostream>

using namespace std;

void Hello(const string& name)
{
	cout << "Hello " << TransformString(name) << endl;
}