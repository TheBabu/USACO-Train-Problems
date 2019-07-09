/*
ID: ten.to.1
TASK: stamps
LANG: C++
*/

#include <iostream>
#include <fstream>

const int MAX_N = 50;
const int MAX_V = 10000;

int stamps[MAX_N];
int dp[MAX_V];

int main()
{
	std::ifstream file_in("stamps.in");
	std::ofstream file_out("stamps.out");
	
	int K, N; file_in >> K >> N;
	for(int i = 0; i < N; i++)
		file_in >> stamps[i];
	
	
}

