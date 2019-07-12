/*
ID: ten.to.1
TASK: stamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

const int MAX_N = 50;
const int MAX_V = 2500000;

int stamps[MAX_N];
int hits[MAX_V];

int main()
{
	std::ifstream file_in("stamps.in");
	std::ofstream file_out("stamps.out");
	
	for(int i = 0; i < MAX_V; i++)
		hits[i] = MAX_V;
	
	int K, N; file_in >> K >> N;
	int min = MAX_V;
	int max = -1;
	
	for(int i = 0; i < N; i++)
	{
		file_in >> stamps[i];
		hits[stamps[i]] = 1;
		min = std::min(min, stamps[i]);
		max = std::max(max, stamps[i]);
	}
	max *= K;
	
	int max_streak = 0;
	int streak     = 0;
	for(int i = min; i <= max; i++)
	{
		if(hits[i] < MAX_V)
		{
			streak++;
			
			for(int n = 0; n < N; n++)
			{
				if(hits[i] < K)
				{
					hits[i + stamps[n]] = std::min(hits[i + stamps[n]], hits[i] + 1);
				}
			}
		}
		else
		{
			max_streak = std::max(max_streak, streak);
			streak = 0;
		}
	}
	max_streak = std::max(max_streak, streak);
	
	file_out << max_streak << '\n';
	
	//Debug
	/*
	for(int i = min; i <= max; i++)
		std::cout << dp[i] << ' ';
	std::cout << '\n';
	for(int i = min; i <= max; i++)
		std::cout << hits[i] << ' ';
	*/
}

