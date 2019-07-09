/*
ID: ten.to.1
TASK: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string.h>

int nodes[1000][1000];

int solve(int R)
{
	for(int i = R - 1; i >= 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			//std::cout << std::max(nodes[i][j], nodes[i][j + 1]) << ' ';
			nodes[i - 1][j] += std::max(nodes[i][j], nodes[i][j + 1]);
		}
		//std::cout << '\n';
	}
	
	return nodes[0][0];
}

int main()
{
	std::ifstream filein("numtri.in");
	std::ofstream fileout("numtri.out");
	
	int R; filein >> R;
	
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < i + 1; j++)
		{
			int v; filein >> v;
			nodes[i][j] = v;
		}
	}
	
	fileout << solve(R) << '\n';
}

