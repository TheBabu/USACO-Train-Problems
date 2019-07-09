/*
ID: ten.to.1
TASK: nocows
LANG: C++
*/ 

//Help from daddy Kevin
//Implementation by Silviu Ganceanu
//Learn how to do!

#include <iostream>
#include <fstream>
#include <string.h>

const int MAX_N = 200;
const int MAX_K = 100;

int dp[MAX_N][MAX_K];

int solve(int n, int k)
{
	if(n == 0 || k == 0)
		return 0;
	if(n == 1)
		return 1;
	if(dp[n][k] != -1)
		return dp[n][k];
	else
	{
		//Generate all possible sums
		int sum = 0;
		for(int i = 1; i < n - 1; i++)
			//Split into 2 subtrees, and find all pedigrees from those
			//1st subtree, just reduce level
			//2nd subtree, reduce level, and also try all different numbers of n values
			sum = (sum + solve(i, k - 1) * solve(n - i - 1, k - 1)) % 9901;
		//Memoize result
		dp[n][k] = sum;
		return sum;
	}
}

int main(){
	std::ifstream file_in("nocows.in");
	std::ofstream file_out("nocows.out");
	
	int N, K; file_in >> N >> K;
	memset(dp, -1, sizeof(dp[0][0]) * MAX_N * MAX_K);
	
	//9901 to make sure value is postive
	file_out << (9901 + solve(N, K) - solve(N, K - 1)) % 9901 << '\n';
}
