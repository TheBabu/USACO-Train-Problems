/*
ID: ten.to.1
LANG: C++
TASK: friday
*/

#include <iostream>
#include <fstream>
#include <map>

bool LeapYear(int year)
{
	if(year % 400 == 0)
	{
		return true;
	}
	else if(year % 100 == 0)
	{
		return false;
	}
	else if(year % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	std::ifstream fridayin("friday.in");
	std::ofstream fridayout("friday.out");
	int totalyrs; fridayin >> totalyrs;
	int dayson13th[7] = {};
	//Starting at 1990
	std::map<int, int> daysmod;
	daysmod[0] = 1;
	daysmod[1] = 2;
	daysmod[2] = 3;
	daysmod[3] = 4;
	daysmod[4] = 5;
	daysmod[5] = 6;
	daysmod[6] = 0;
	
	int monthdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int curryear = 1900;
	int dayafter1990 = 13;
	for(int i = 1; i <= totalyrs; i++)
	{
		if(LeapYear(curryear) == true)
		{
			monthdays[1] = 29;
			
		}
		else
		{
			monthdays[1] = 28;
		}
		
		for(int n = 0; n <= 11; n++)
		{
			dayson13th[daysmod[dayafter1990 % 7]] += 1;
			dayafter1990 += monthdays[n];
		}
		curryear += 1;
	}
	
	//Write to file
	//WHY NO RANGE BASED LOOP COMPILE!?
	for(int i = 0; i < 7; i++)
	{
		if(i != 6)
		{
			fridayout << dayson13th[i] << " ";
		}
		else
		{
			fridayout << dayson13th[i];
		}
	}
	fridayout << std::endl;
}

