/*
ID: ten.to.1
TASK: runround
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string.h>

bool is_unique(std::string digits)
{
	for(int i = 0; i < digits.length(); i++)
	{
		for(int j = i + 1; j < digits.length(); j++)
		{
			if(digits[i] == digits[j])
				return false;
		}
	}
	
	return true;
}

bool is_runround(int n)
{
	std::string digits = std::to_string(n);
	bool touched[digits.length()];
	memset(touched, false, digits.length());
	
	if(!is_unique(digits))
		return false;
	
	for(int i = 0; i < digits.length(); i++)
		if(digits[i] == '0')
			return false;
	
	int moves = 0;
	
	for(int i = 0; i < digits.length(); i++)
	{
		//-48 to convert ASCII value to Decimal value
		moves += digits[moves % digits.length()] - 48;
		touched[moves % digits.length()] = true;
	}
	
	for(int i = 0; i < digits.length(); i++)
		if(!touched[i])
			return false;
	
	if(digits[moves % digits.length()] == digits[0])
		return true;
	else
		return false;
	
}

int main()
{
	std::ifstream file_in("runround.in");
	std::ofstream file_out("runround.out");
	
	int M; file_in >> M;
	
	M++;
	while(!is_runround(M))
		M++;
	
	file_out << M << '\n';
}

