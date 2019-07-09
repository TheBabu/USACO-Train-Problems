/*
ID: ten.to.1
TASK: zerozum
LANG: C++
*/

#include <iostream>
#include <fstream>

void solve(std::string b, int n, int sum, const int& N)
{
	char choose[] = {'+', '-', ' '};
	
	if(n == N)
	{
		b += std::to_string(N);
		
		std::cout << b << '\n';
		
		return;
	}
	
	for(int i = 0; i < 3; i++)
	{
		solve(b + std::to_string(n) + choose[i], n + 1, sum, N);
	}
}

int main()
{
	std::ifstream file_in("zerosum.in");
	std::ofstream file_out("zersum.out");
	
	int N; file_in >> N;
	
	solve("", 1, 0, N);
}

