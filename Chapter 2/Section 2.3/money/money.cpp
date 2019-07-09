/*
ID: ten.to.1
TASK: money
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string.h>

//Implementation by zzh8829
//Learn how to do!

const long long MAX = 11;

long long V, N;
long long coins[25];
long long dp[MAX];

int main()
{
	std::ifstream file_in("money.in");
	std::ofstream file_out("money.out");
	
	file_in >> V >> N;
	for(int i = 0; i < V; i++)
		file_in >> coins[i];
	
	dp[0] = 1;
	
	//Debug
	std::cout << "0 1 2 3 4 5 6 7 8 9 10\n----------------------\n";
	for(int i = 0; i < V; i++)
	{
		for(int j = coins[i]; j <= N; j++)
		{
			dp[j] += dp[j - coins[i]];
			
			//Debug
			for(int i : dp)
				std::cout << i << ' ';
			std::cout << '\n';
		}
		std::cout << "----------------------\n";
	}
	
	file_out << dp[N] << '\n';
}

