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
	
	bool operator==(BuckStat const &b)
	{
		if(this->levels[1] == b.levels[1] && this->levels[2] == b.levels[2] && this->levels[3] == b.levels[3])
		{
			return true;
		}
		
		return false;
	}
};

std::vector<int> solve_util(BuckStat buck, std::vector<BuckStat> visited)
{
	std::vector<int> buckC_level;
	for(std::vector<BuckStat>::const_iterator i = visited.begin(); i != visited.end(); ++i) std::cout << "Visited: " << i->levels[1] << ' ' << i->levels[2] << ' '<< i->levels[3] << ", ";
	std::cout << '\n';
	if(buck.levels[1] == 0)
	{
		buckC_level.push_back(buck.levels[3]);
		visited.push_back(buck);
		return buckC_level;
	}
	
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			//std::cout << i << ' ' << j << std::endl;
			BuckStat poured = buck.fill_bucket(i, j);
			
			bool not_visited = true;
			
			for(int i = 0; i < visited.size(); i++)
			{
				if(poured == visited[i])
				{
					not_visited = false;
					break;
				}
			}
			
			if(i != j && buck.levels[i] > 0 && not_visited && !(poured == buck))
			{
				std::cout << "Lower Solve: " << poured.levels[1] << ' ' << poured.levels[2] << ' ' << poured.levels[3] << '\n';
				
				std::vector<int> temp = solve_util(poured, visited);
				buckC_level.insert(buckC_level.end(), temp.begin(), temp.end());
			}
		}
	}
	
	return buckC_level;
}

std::vector<int> solve(BuckStat buck)
{
	std::vector<int> buckC_level;
	std::vector<BuckStat> visited;
	visited.push_back(buck);
	buckC_level.push_back(buck.levels[3]);
	for(std::vector<BuckStat>::const_iterator i = visited.begin(); i != visited.end(); ++i) std::cout << "Visited: " << i->levels[1] << ' ' << i->levels[2] << ' '<< i->levels[3] << ", ";
	std::cout << '\n';
	
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			//std::cout << i << ' ' << j << std::endl;
			BuckStat poured = buck.fill_bucket(i, j);
			if(i != j && buck.levels[i] > 0)
			{
				//std::cout << buck.levels[1] << ' ' << buck.levels[2] << ' ' << buck.levels[3] << '\n';
				std::cout << "Main Solve: " << poured.levels[1] << ' ' << poured.levels[2] << ' ' << poured.levels[3] << '\n';
				std::vector<int> temp = solve_util(poured, visited);
				buckC_level.insert(buckC_level.end(), temp.begin(), temp.end());
			}
		}
	}
	
	return buckC_level;
}

/*
std::vector<int> solve(BuckStat buck)
{
	std::vector<int> buckC_level;
	std::vector<BuckStat> vec_bucks;
	vec_bucks.push_back(buck);
	
	for(int z = 0; z <= 6; z++)
	{
		//for(std::vector<int>::const_iterator i = buckC_level.begin(); i != buckC_level.end(); ++i) std::cout << *i << ' ';
		int size_of_multp_bucks = vec_bucks.size();
		for(int k = 0; k < size_of_multp_bucks; k++)
		{
			//Push Back Resulting Poured Buckets
			for(int i = 1; i <= 3; i++)
			{
				for(int j = 1; j <= 3; j++)
				{
					if(i != j && vec_bucks[k].levels[i] > 0)
					{
						//std::cout << i << " " << j << std::endl;
						vec_bucks.push_back(vec_bucks[k].fill_bucket(i, j));
					}
				}
			}
		}
		
		//Remove multplying bucks
		for(int k = 0; k < size_of_multp_bucks; k++)
		{
			vec_bucks.erase(vec_bucks.begin() + k);
		}
		
		//Check if A == 0
		std::vector<int> delete_later;
		for(int k = 0; k < vec_bucks.size(); k++)
		{
			if(vec_bucks[k].levels[1] == 0)
			{
				buckC_level.push_back(vec_bucks[k].levels[3]);
				delete_later.push_back(k);
			}
		}
		
		//std::cout << buckC_level.size() << std::endl;
		//std::cout << delete_later.size() << std::endl;
		
		//Delete buckstats that have reached A == 0
		for(int k = 0; k < delete_later.size(); k++)
		{
			vec_bucks.erase(vec_bucks.begin() + delete_later[k]);
		}
	}
	
	return buckC_level;
}
*/

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
}

