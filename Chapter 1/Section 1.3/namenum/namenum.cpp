/*
ID: ten.to.1
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

int main()
{
	//Files
	std::ifstream namenumin("namenum.in");
	std::ofstream namenumout("namenum.out");
	std::ifstream dict("dict.txt");
	
	//Variables
	std::string numnamestring; namenumin >> numnamestring;
	std::vector<int> numname;
	std::vector<int> chariter;
	int numnamelength;
	char keymaps[10][3] = 
	{
		//Space is not a limiting factor!
		{' ',' ',' '},
		{' ',' ',' '},
		{'A','B','C'},
		{'D','E','F'},
		{'G','H','I'},
		{'J','K','L'},
		{'M','N','O'},
		{'P','R','S'},
		{'T','U','V'},
		{'W','X','Y'}
	};
	
	//String to Vector & Create chariter Vector
	for(auto const &numstring : numnamestring)
	{
		numname.push_back(numstring - '0');
		chariter.push_back(0);
	}
	numnamelength = numname.size();
	
	//Brute Force
	for(int i = 0; i < pow(3, numnamelength); i++)
	{
		
		
		for(auto const &charnum : chariter)
		{
			std::cout << charnum;
		}
		std::cout << '\n';
	}
	//PROBABLY EASIER IN PYTHON
}

