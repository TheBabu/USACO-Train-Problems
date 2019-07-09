/*
ID: ten.to.1
TASK: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct BuckStat
{
	int cap[4];
	int levels[4];
	
	BuckStat(int a, int b, int c)
	{
		cap[1] = a;
		cap[2] = b;
		cap[3] = c;
		
		levels[1] = 0;
		levels[2] = 0;
		levels[3] = c;
	}
	
	BuckStat fill_bucket(int from, int to)
	{
		BuckStat new_buck = *this;
		
		if(new_buck.cap[to] >= new_buck.levels[to] + new_buck.levels[from])
		{
			new_buck.levels[to]   = new_buck.levels[to] + new_buck.levels[from];
			new_buck.levels[from] = 0;
		}
		else
		{
			new_buck.levels[to]   = new_buck.cap[to];
			new_buck.levels[from] = new_buck.levels[from] - (cap[to] - levels[to]);
		}
		
		return new_buck;
	}
	
	bool can_pour(int from, int to)
	{
		if(from == to)
		{
			return false;
		}
		else if(levels[from] == 0)
		{
			return false;
		}
		else if(levels[to] == cap[to])
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
	bool operator==(BuckStat const &b)
	{
		if(this->levels[1] == b.levels[1] && this->levels[2] == b.levels[2] && this->levels[3] == b.levels[3])
		{
			return true;
		}
		
		return false;
	}
};

std::vector<BuckStat> visited;

std::vector<int> solve_util(BuckStat buck)
{
	for(BuckStat i : visited)
	{
		std::cout << "Visited: " << i.levels[1] << ' ' << i.levels[2] << ' ' << i.levels[3] << std::endl;
	}
	std::cout << buck.levels[1] << ' ' << buck.levels[2] << ' ' << buck.levels[3] << std::endl;
	
	std::vector<int> buckC_level;
	
	//Case 1 Visited
	if(buck.levels[1] == 0)
	{
		visited.push_back(buck);
		buckC_level.push_back(buck.levels[3]);
		//Exit
		return buckC_level;
	}
	
	//Pour Buckets if possible
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			if(buck.can_pour(i, j))
			{
				//Check if poured is in visited
				BuckStat poured = buck.fill_bucket(i, j);
				bool go = true;
				
				for(int i = 0; i < visited.size(); i++)
				{
					if(poured == visited[i])
					{
						go = false;
					}
				}
				
				if(go == true)
				{
					std::vector<int> temp = solve_util(poured);
					buckC_level.insert(buckC_level.end(), temp.begin(), temp.end());
				}
			}
		}
	}
	
	//Case 2 visited
	visited.push_back(buck);
	
	return buckC_level;
}

std::vector<int> solve(BuckStat buck)
{
	std::vector<int> buckC_level;
	buckC_level.push_back(buck.levels[3]);
	
	visited.push_back(buck);
	
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			if(buck.can_pour(i, j))
			{
				BuckStat poured = buck.fill_bucket(i, j);
				
				std::vector<int> temp = solve_util(poured);
				buckC_level.insert(buckC_level.end(), temp.begin(), temp.end());
			}
		}
	}
	
	return buckC_level;
}

int main()
{
	std::ifstream filein("milk3.in");
	std::ofstream fileout("milk3.out");
	
	int a; filein >> a;
	int b; filein >> b;
	int c; filein >> c;
	
	BuckStat og_bucks(a, b, c);
	std::vector<int> solution = solve(og_bucks);
	std::sort(solution.begin(), solution.end());
	solution.erase(std::unique(solution.begin(), solution.end()), solution.end());
	
	for(int i = 0; i < solution.size(); i++)
	{
		if(i == (solution.size() - 1))
		{
			fileout << solution[i];
		}
		else
		{
			fileout << solution[i] << ' ';
		}
	}
	fileout << '\n';
};
