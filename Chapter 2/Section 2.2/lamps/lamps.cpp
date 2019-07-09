/*
ID: ten.to.1
TASK: lamps
LANG: C++
*/

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream file_in("lamps.in");
	std::ofstream file_out("lamps.out");
	
	int N; file_in >> N;
	int known_config[N + 1];
	
	for(int i = 0; i < N + 1; i++)
		known_config[i] = -1;
	
	int C; file_in >> C;
	
	int inp; file_in >> inp;
	while(inp != -1)
	{
		known_config[inp] = 1;
		file_in >> inp;
	}
	
	file_in >> inp;
	
	while(inp != -1)
	{
		known_config[inp] = 0;
		file_in >> inp;
	}
}

