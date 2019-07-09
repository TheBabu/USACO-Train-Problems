/*
ID: ten.to.1
TASK: inflate
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

const int MAX_P = 10000;
const int MAX_M = 10000;
const int MAX_N = 10000;

int points[MAX_P];
int minutes[MAX_M];
int dp[MAX_N][MAX_M];

//TOO MANY RECURSIVE CALLS (MORE THAN 16MB)
int solve(int n, int m)
{
	int res = -1;
	
	if(dp[n][m] != -1)
		return dp[n][m];
	
	if(n == 0)
	{
		res = 0;
	}
	else if(minutes[n] > m)
	{
		res = solve(n - 1, m);
	}
	else
	{
		int add_skip = points[n] + solve(n - 1, m - minutes[n]);
		int add_stay = points[n] + solve(n, m - minutes[n]);
		int skip     = solve(n - 1, m);
		
		res = std::max(std::max(add_skip, add_stay), skip);
	}
	
	dp[n][m] = res;
	return res;
}

int main()
{
	std::ifstream file_in("inflate.in");
	std::ofstream file_out("inflate.out");
	
	int M, N; file_in >> M >> N;
	for(int i = 0; i < N; i++)
		file_in >> points[i] >> minutes[i];
	
	for(int i = 0; i < MAX_N; i++)
		for(int j = 0; j < MAX_M; j++)
			dp[i][j] = -1;
	
	file_out << solve(N - 1, M) << '\n';
}

