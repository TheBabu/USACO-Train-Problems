/*
 * ID: ten.to.1
 * TASK: holstein
 * LANG: C++
*/

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream file_in("holstein.in");
	std::ofstream file_out("holstein.out");
	
	int V; file_in >> V;
	int min_vit[V];
	for(int i = 0; i < V; i++)
	{
		int r; file_in >> r;
		min_vit[i] = r;
	}
	
	int G; file_in >> G;
	int feeds[G][V];
	for(int i = 0; i < G; i++)
	{
		for(int j = 0; j < V; j++)
		{
			int r; file_in >> r;
			feeds[i][j] = r;
		}
	}
}

