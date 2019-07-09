/*
ID: ten.to.1
TASK: humble
LANG: C++
*/

#include <iostream>
#include <fstream>

const int MAX_K = 100;
const int MAX_N = 100000;

int primes[MAX_K];
int S[MAX_N];

int main()
{
	std::ifstream file_in("humble.in");
	std::ofstream file_out("humble.out");
	
	int K, N; file_in >> K >> N;
	for(int i = 0; i < K; i++)
		file_in >> primes[i];
	
	
}

