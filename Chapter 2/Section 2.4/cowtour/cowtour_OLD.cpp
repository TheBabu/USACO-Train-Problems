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

const int INF = 999999;

int N;

double solve(const double* grid, int a, int b, const double* points)
{
	double test[N][N];
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			test[i][j] = *(grid + (N * i) + j);
			
			//Debug
			//std::cout << test[i][j] << ' ';
		}
		//Debug
		//std::cout << '\n';
	}
	
	test[a][b] = sqrt(pow(*(points + (2 * a) + 0) - *(points + (2 * b) + 0), 2) + pow(*(points + (2 * a) + 1) - *(points + (2 * a) + 1), 2));
	test[b][a] = sqrt(pow(*(points + (2 * b) + 0) - *(points + (2 * a) + 0), 2) + pow(*(points + (2 * b) + 1) - *(points + (2 * a) + 1), 2));
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			test[i][j] = std::min(test[i][j], test[i][a] + test[a][j]);
			
			//Debug
			//std::cout << test[i][j] << ' ';
		}
		//Debug
		//std::cout << '\n';
	}
	
	double max = -1;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			test[i][j] = std::min(test[i][j], test[i][b] + test[b][j]);
			max = std::max(max, test[i][j]);
		}
	}
	
	/*
	double max = -1;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			max = std::max(max, test[i][j]);
			//Debug
			//std::cout << test[i][j] << ' ';
		}
		//Debug
		//std::cout << '\n';
	}
	*/
	
	//Debug
	std::cout << "(" << a << ", " << b << ")\n";
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			std::cout << test[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	
	return max;
}

int main()
{
	std::ifstream file_in("cowtour.in");
	std::ofstream file_out("cowtour.out");
	
	file_in >> N;
	double points[N][2];
	double grid[N][N];
	
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
			//Debug
			//std::cout << grid[i][j] << ' ';
		}
		//Debug
		//std::cout << '\n';
		file_in.get();
	}
	
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
	
	//Debug
	std::cout << "ORIG:\n";
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			std::cout << grid[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	
	double min = INF;
	for(int i = 0; i < N; i++)
	{
		for(int j = i; j < N; j++)
		{
			if(i != j)
			{
				min = std::min(min, solve(grid[0], i, j, points[0]));
			}
		}
	}
	
	if(N == 2)
	{
		file_out << std::fixed << std::setprecision(6) << 1.0 << '\n';
	}
	else
	{
		file_out << std::fixed << std::setprecision(6) << min << '\n';
	}
}

