/*
ID: ten.to.1
LANG: C++
TASK: test
*/

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream TestIn("test.in");
	std::ofstream TestOut("test.out");
	
	int a, b;
	TestIn >> a >> b;
	TestOut << a + b << "\n";
}

