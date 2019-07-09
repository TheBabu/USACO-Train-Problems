/*
ID: ten.to.1
LANG: C++
TASK: palsqure
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Base X <= 10
int base10tobaseX(int base10num, int baseX)
{
	int numbaseX = 0;
	int k = 1;
	
	while(base10num > 0)
	{
		numbaseX += (base10num % baseX) * k;
		k *= 10;
		base10num /= baseX;
	}
	
	return numbaseX;
}

bool checkpalindrome()
{
	
}

int main()
{
	//Files
	std::ifstream palsquarein("palsquare.in");
	std::ofstream palsquareout("palsquare.out");
	
	//Variables
	int base; palsquarein >> base;
	int maxnum = 300;
	
	//Brute Force
	for(int num; num <= maxnum; num++)
	{
		
	}
	//WHY DID I START THIS IN C++?
}

