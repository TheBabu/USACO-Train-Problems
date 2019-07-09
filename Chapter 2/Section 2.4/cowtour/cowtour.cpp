/*
ID: ten.to.1
TASK: cowtour
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <iomanip>

//Some help from analysis from Russ Cox
//Just think about it more! (Pen and Paper)

const int INF = 999999;

int N;

int id = 1;
void dfs(bool* visited, double* grid, int cur, int* types)
{
	visited[cur] = true;
	types[cur]   = id;
	
	for(int i = 0; i < N; i++)
		if(!visited[i] && *(grid + N * cur + i) < INF)
			dfs(visited, grid, i, types);
}

int main()
{
	std::ifstream file_in("cowtour.in");
	std::ofstream file_out("cowtour.out");
	
	file_in >> N;
	double points[N][2];
	double grid[N][N];
	bool visited[N];
	int types[N];
	
	for(int i = 0; i < N; i++)
	{
		file_in >> points[i][0] >> points[i][1];
	}
	
	file_in.get();
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(file_in.get() - 48)
			{
				grid[i][j] = sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2));
			}
			else
			{
				grid[i][j] = INF;
			}
		}
		file_in.get();
	}
	
	for(int i = 0; i < N; i++)
		visited[i] = false;
	
	for(int i = 0; i < N; i++)
	{
		if(!visited[i])
		{
			dfs(visited, grid[0], i, types);
			id++;
		}
	}
	
	//Debug
	//for(int i = 0; i < N; i++)
	//	std::cout << types[i] << ' ';
	
	for(int k = 0; k < N; k++)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				grid[i][j] = std::min(grid[i][j], grid[i][k] + grid[k][j]);
			}
		}
	}
	
	for(int i = 0; i < N; i++)
		grid[i][i] = 0;
	
	double max_g = -1;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(grid[i][j] != INF)
			{
				max_g = std::max(max_g, grid[i][j]);
			}
		}
	}
	
	double min = INF;
	for(int a = 0; a < N; a++)
	{
		for(int b = a; b < N; b++)
		{
			if(a != b && types[a] != types[b])
			{
				double max_1 = -1;
				
				//Debug
				//std::cout << "A:\n";
				for(int i = 0; i < N; i++)
				{
					//std::cout << grid[a][i] << '\n';
					if(grid[a][i] > max_1 && grid[a][i] != INF)
					{
						max_1 = grid[a][i];
					}
				}
				
				double max_2 = -1;
				
				//std::cout << "B:\n";
				for(int i = 0; i < N; i++)
				{
					//std::cout << grid[b][i] << '\n';
					if(grid[b][i] > max_2 && grid[b][i] != INF)
					{
						max_2 = grid[b][i];
					}
				}
				
				//std::cout << "STATS: " << a << ' ' << b << " | " << max_1 + max_2 + sqrt(pow(points[a][0] - points[b][0], 2) + pow(points[a][1] - points[b][1], 2)) << " | " << max_g << "\n\n";
				min = std::max(std::min(min, max_1 + max_2 + sqrt(pow(points[a][0] - points[b][0], 2) + pow(points[a][1] - points[b][1], 2))), max_g);
			}
		}
	}
	
	file_out << std::fixed << std::setprecision(6) << min << '\n';
}

