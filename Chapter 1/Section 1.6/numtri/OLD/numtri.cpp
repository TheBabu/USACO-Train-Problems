/*
ID: ten.to.1
TASK: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

int nodes[1000][1000];

int sum_fact(int n)
{
	return (n == 0) ? 0 : sum_fact(n - 1) + n;
}

void solve(int p, int q, int sum, int R, int& max)
{
	sum += nodes[p][q];
	
	if(p == R - 1)
	{
		//std::cout << sum << ' ';
		max = std::max(sum, max);
		return;
	}
	
	solve(p + 1, q, sum, R, max);
	solve(p + 1, q + 1, sum, R, max);
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
	
	int max = -1;
	solve(0, 0, 0, R, max);
	fileout << max << '\n';
}

