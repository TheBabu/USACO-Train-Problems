/*
ID: ten.to.1
TASK: humble
LANG: C++
*/

//Help from Russ Cox
//Idea of pindex

#include <iostream>
#include <fstream>

const int MAX_K = 100;
const int MAX_N = 100000;

long int P[MAX_K];
long int S[MAX_N];
long int pindex[MAX_K];

int main()
{
	std::ifstream file_in("humble.in");
	std::ofstream file_out("humble.out");
	
	int K, N; file_in >> K >> N;
	for(int i = 0; i < K; i++)
		file_in >> P[i];
	
	S[0] = 1;
	
	for(int s = 0; s <= N; s++)
	{
		long int min = -1;
		//std::cout << "--- s: " << s << " ---\n";
		for(int p = 0; p < K; p++)
		{
			for(int i = pindex[p]; i <= s; i++)
			{
				//std::cout << S[i] << ' ' << P[p] << '\n';
				long int test_humble = S[i] * P[p];
				if((test_humble > S[s] && test_humble < min) || (test_humble > S[s] && min == - 1))
				{
					min       = test_humble;
					pindex[p] = i;
				}
			}
			//std::cout << '\n';
		}
		
		S[s + 1] = min;
	}
	
	file_out << S[N] << '\n';
	
	//Debug
	//for(int i = 0; i <= N; i++)
	//	std::cout << S[i] << ' ';
	
	//for(int i = 0; i < K; i++)
	//	std::cout << pindex[i] << ' ';
}

