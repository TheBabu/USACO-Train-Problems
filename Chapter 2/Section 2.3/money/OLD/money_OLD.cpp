/*
ID: ten.to.1
TASK: money
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string.h>

const long long MAX = 110;

long long V, N;
long long combs[25][MAX];
long long dp[25][MAX];

void dfs(long long  i, long long j, long long & pos)
{
	//std::cout << i << " : " << dp[i][j] << '\n';
	
	if(dp[i][j] == N)
	{
		pos++;
		return;
	}
	
	//No need to check beyond V
	if(i == V)
	{
		return;
	}
	
	for(long long k = 0; k < MAX; k++)
	{
		if(combs[i + 1][k] != -1 && combs[i + 1][k] <= N - dp[i][j])
		{
			dp[i + 1][k] += dp[i][j] + combs[i + 1][k];
			dfs(i + 1, k, pos);
		}
	}
	
	dp[i][j] = 0;
}

int main()
{
	std::ifstream file_in("money.in");
	std::ofstream file_out("money.out");
	
	file_in >> V >> N;
	for(long long i = 0; i < 25; i++)
		for(long long j = 0; j < MAX; j++)
			combs[i][j] = -1;
	
	for(long long i = 0; i < V; i++)
	{
		long long inp; file_in >> inp;
		
		for(long long j = 0; j <= (N / inp); j++)
		{
			combs[i][j] = j * inp;
		}
	}
	
	//Debug
	/*
	for(long long i = 0; i < 25; i++)
	{
		for(long long j = 0; j < MAX; j++)
		{
			std::cout << combs[i][j] << ' ';
		}
		std::cout << '\n';
	}
	*/
	
	long long ans = 0;
	
	for(long long i = 0; i < V; i++)
	{
		for(long long j = 1; j < MAX; j++)
		{
			if(combs[i][j] != -1)
			{
				long long pos = 0;
				
				//std::cout << "INIT: " << i << ' ' << j << "\n";
				dp[i][j] = combs[i][j];
				dfs(i, j, pos);
				//std::cout << "COMBS: " << pos << "\n\n";
				
				ans += pos;
			}
			else
			{
				break;
			}
		}
	}
	
	file_out << ans << '\n';
}

