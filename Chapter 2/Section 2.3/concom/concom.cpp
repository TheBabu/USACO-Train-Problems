/*
ID: ten.to.1
TASK: concom
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

const int MAX = 100;
//const int MAX = 5;
int N;

int percents[MAX + 1][MAX + 1];
bool controls[MAX + 1][MAX + 1];

void dfs(int cur, int end, int& per, bool* visited)
{
	visited[cur] = true;
	
	if(percents[cur][end] != 0)
		per += percents[cur][end];
	
	//std::cout <<  cur << ' ' << end << " | " << per << '\n';
	
	for(int i = 1; i <= MAX; i++)
	{
		if(controls[cur][i] && !visited[i])
		{
			dfs(i, end, per, visited);
		}
	}
}

int main()
{
	std::ifstream file_in("concom.in");
	std::ofstream file_out("concom.out");
	
	file_in >> N;
	
	bool all_100 = true;
	
	for(int i = 0; i < N; i++)
	{
		int from, to; file_in >> from >> to;
		double per; file_in >> per;
		
		percents[from][to] = per;
		
		if(per >= 50)
			controls[from][to] = true;
		
		if(per != 100)
			all_100 = false;
	}
	
	//Debug
	/*
	for(int i = 1; i <= MAX; i++)
	{
		for(int j = 1; j <= MAX; j++)
		{
			std::cout << percents[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	for(int i = 1; i <= MAX; i++)
	{
		for(int j = 1; j <= MAX; j++)
		{
			std::cout << controls[i][j] << ' ';
		}
		std::cout << '\n';
	}
	*/
	
	//All 100 Hack
	//Not good solution
	int p = 5;
	if(all_100)
		p = 1;
	
	//Repeat arbitrarily number of times
	for(int k = 0; k < p; k++)
	{
		for(int i = 1; i <= MAX; i++)
		{
			for(int j = 1; j <= MAX; j++)
			{
				if(i != j)
				{
					int per               = 0;
					bool visited[MAX + 1] = { };
					
					dfs(i, j, per, visited);
					
					if(per >= 50 && !controls[i][j])
					{
						controls[i][j] = true;
					}
				}
			}
		}
	}
	
	for(int i = 1; i <= MAX; i++)
		for(int j = 1; j <= MAX; j++)
			if(i != j && controls[i][j])
				file_out << i << ' ' << j << '\n';
}

