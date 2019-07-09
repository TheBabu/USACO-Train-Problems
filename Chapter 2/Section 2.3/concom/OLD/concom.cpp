/*
ID: ten.to.1
TASK: concom
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

int N;
const int MAX = 5;

struct Company
{
	double control[MAX + 1];
	
	Company()
	{
		for(int i = 1; i <= MAX; i++)
			control[i] = 0;
	}
};

void dfs_util(Company* companies, bool* visited, std::vector<double>& ans, int curr, int end, double per)
{
	visited[curr] = true;
	
	if(curr == end)
		ans.push_back(per);
	
	for(int i = 1; i <= MAX; i++)
	{
		if(!visited[i])
			dfs_util(companies, visited, ans, i, end, companies[curr].control[i]);
	}
}

double dfs(Company* companies, bool* visited, int curr, int end, double per)
{
	std::vector<double> ans;
	
	for(int i = 1; i <= MAX; i++)
	{
		dfs_util(companies, visited, ans, i, end, companies[curr].control[i]);
	}
	
	double max = -1;
	for(int i = 0; i < ans.size(); i++)
		max = ans[i] > max ? ans[i] : max;
	
	return max;
}

int main()
{
	std::ifstream file_in("concom.in");
	std::ofstream file_out("concom.out");
	
	file_in >> N;
	Company companies[MAX + 1];
	for(int i = 0; i < N; i++)
	{
		int from, to; file_in >> from >> to;
		double percent; file_in >> percent;
		
		companies[from].control[to] = percent / 100;
	}
	
	/*
	for(int i = 1; i <= MAX; i++)
	{
		for(int j = 1; j <= MAX; j++)
		{
			std::cout << companies[i].control[j] << ' ';
		}
		std::cout << '\n';
	}
	*/
	
	for(int i = 1; i <= MAX; i++)
	{
		for(int j = 1; j <= MAX; j++)
		{
			if(i != j)
			{
				bool visited[MAX + 1];
				for(int i = 1; i <= MAX; i++)
					visited[i] = false;
				
			}
		}
	}
}

