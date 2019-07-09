/*
ID: ten.to.1
TASK: inflate
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

//Help from https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/

const int MAX_P = 10000;
const int MAX_M = 10000;

int points[MAX_P];
int minutes[MAX_M];
int dp[MAX_M]; 

int main()
{
	std::ifstream file_in("inflate.in");
	std::ofstream file_out("inflate.out");
	
	int M, N; file_in >> M >> N;
	for(int i = 0; i < N; i++)
		file_in >> points[i] >> minutes[i];
	
	for(int i = 0; i <= M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(minutes[j] <= i)
			{
				//Either max by itself or of subproblem
				dp[i] = std::max(dp[i], dp[i - minutes[j]] + points[j]);
				//dp[i] = current max points with max weight i
				//minutes[j] = added weight
				//i = current max weight
				//i - minutes[j] = current max weight minus added weight
				//dp[i - minutes[j]] = max points possible of " "
				//points[j] = added points
			}
		}
	}
	
	//Debug
	//for(int i = 0; i <= M; i++)
	//	std::cout << i << " | " << dp[i] << '\n';
	
	file_out << dp[M] << '\n';
}

