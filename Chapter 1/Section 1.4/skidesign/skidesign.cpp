#include <iostream>
#include <fstream>
#include <cmath>

/*
ID: ten.to.1
TASK: skidesign
LANG: C++
*/
//Use index based loops for better performance!

int main()
{
	std::ifstream filein("skidesign.in");
	std::ofstream fileout("skidesign.out");
	
	int N; filein >> N;
	int current_heights[N];
	int max_height = 0;
	for(int i = 0; i <= N; i++)
	{
		int inp; filein >> inp;
		current_heights[i] = inp;
		
		max_height = std::max(inp, max_height);
	}
	
	int min_cost = 999999;
	
	//Brute Force
	for(int b = 1; b <= max_height; b++)
	{
		int current_cost = 0;
		
		for(int h = 0; h < N; h++)
		{
			if(current_heights[h] < b)
			{
				current_cost += std::pow((b - current_heights[h]), 2);
			}
			else if(current_heights[h] > (b + 17))
			{
				current_cost += std::pow((current_heights[h] - (b + 17)), 2);
			}
		}
		
		min_cost = std::min(current_cost, min_cost);
	}
	
	fileout << min_cost << "\n";
}

