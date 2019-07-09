/*
ID: ten.to.1
TASK: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <bitset>

#define Bit std::bitset<8>

int hamming_dist(int a, int b)
{
	return Bit(a ^ b).count();
}

int main()
{
	std::ifstream file_in("hamming.in");
	std::ofstream file_out("hamming.out");
	
	int N, B, D; file_in >> N >> B >> D;
	int max = pow(2, B);
	int hammings[max + 1][max + 1];
	
	for(int i = 0; i <= max; i++)
	{
		for(int j = i; j <= max; j++)
		{
			hammings[i][j] = hamming_dist(i, j);
		}
	}
	
	int codes[N]; codes[0] = 0;
	int count = 0;
	
	for(int i = 0; i <= max; i++)
	{
		bool add = true;
		std::cout << "Current: " << i << ' ';
		for(int j = 0; j <= count; j++)
		{
			int check_num = codes[j];
			std::cout << '(' << check_num << ", " << hammings[check_num][i] << ") ";
			if(hammings[check_num][i] < D)
				add = false;
		}
		if(add)
		{
			std::cout << "HIT";
			count++;
			codes[count] = i;
		}
		std::cout << '\n';
	}
	
	for(int i : codes)
		std::cout << i << ' ';
	
	for(int i = 0; i < N; i++)
	{
		if(i == N - 1)
			file_out << codes[i] << '\n';
		else if((i + 1) % 10 == 0)
			file_out << codes[i] << '\n';
		else
			file_out << codes[i] << ' ';
	}
}

