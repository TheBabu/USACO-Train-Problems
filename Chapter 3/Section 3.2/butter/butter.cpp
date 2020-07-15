/*
ID: ten.to.1
TASK: butter
LANG: C++
*/

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream file_in("butter.in");
	std::ofstream file_out("butter.out");
	
	int N, P, C; file_in >> N >> P >> C;
	int pastures_with_cows[N];
	int distances[P + 1][P + 1];
	
	//Setup
	for(int i = 0; i < N; i++)
	{
		file_in >> pastures_with_cows[i];
	}
	
	for(int i = 1; i <= P; i++)
	{
		for(int j = 1; j <= P; j++)
		{
			if(i == j)
				distances[i][j] = 0;
			else
				distances[i][j] = 999;
		}
	}
	
	for(int i = 0; i < C; i++)
	{
		int pasture_a, pasture_b, distance; file_in >> pasture_a >> pasture_b >> distance;
		
		distances[pasture_a][pasture_b] = distance;
		distances[pasture_b][pasture_a] = distance;
	}
	
	//Floyd-Warshall Algorithm
	for (int k = 1; k <= P; k++)
	{
		for (int i = 1; i <= P; i++)
		{
			for (int j = 1; j <= P; j++)
			{
				distances[i][j] = std::min(distances[i][j], distances[i][k] + distances[k][j]);
			}
		}
	}
	
	//Debug
	/*
	for(int i = 1; i <= P; i++)
	{
		for(int j = 1; j <= P; j++)
		{
			std::cout << distances[i][j] << ' ';
		}
		std::cout << '\n';
	}
	for(int i = 0; i < N; i++)
	{
		std::cout << pastures_with_cows[i] << ' ';
	}
	std::cout << '\n';
	*/
	
	int min_distance = 999999999;
	for(int i = 1; i <= P; i++)
	{
		int distance = 0;
		
		for(int j = 0; j < N; j++)
		{
			distance += distances[i][pastures_with_cows[j]];
		}
		
		min_distance = std::min(min_distance, distance);
	}
	
	file_out << min_distance << '\n';
}

