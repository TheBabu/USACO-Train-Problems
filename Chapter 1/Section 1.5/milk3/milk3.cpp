/*
ID: ten.to.1
TASK: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Buckets
{
	int caps[4];
	int levels[4];
	
	Buckets(int a, int b, int c)
	{
		caps[1] = a;
		caps[2] = b;
		caps[3] = c;
		
		levels[1] = 0;
		levels[2] = 0;
		levels[3] = c;
	}
	
	bool operator==(Buckets const &a)
	{
		if(a.levels[1] == this->levels[1] && a.levels[2] == this->levels[2] && a.levels[3] == this->levels[3])
		{
			return true;
		}
		
		return false;
	}
};

Buckets fill_buckets(Buckets unp, int from, int to)
{
	Buckets pou = unp;
	
	if(pou.caps[to] >= pou.levels[to] + pou.levels[from])
	{
		pou.levels[to]   = pou.levels[to] + pou.levels[from];
		pou.levels[from] = 0;
	}
	else
	{
		pou.levels[to]   = pou.caps[to];
		pou.levels[from] = pou.levels[from] - (unp.caps[to] - unp.levels[to]);
	}
	
	return pou;
}

bool poss_fill(Buckets unp, Buckets pou, std::vector<Buckets> visited)
{
	for(int i = 0; i < visited.size(); i++)
	{
		if(pou == visited[i])
		{
			return false;
		}
	}
	
	if(unp == pou)
	{
		return false;
	}
	
	return true;
}

std::vector<int> solve(Buckets bucks, std::vector<Buckets> visited)
{
	//std::cout << bucks.levels[1] << ' ' << bucks.levels[2] << ' ' << bucks.levels[3] << '\n';
	
	std::vector<int> bucket_C_levels;
	visited.push_back(bucks);
	
	//Check if Bucket A is Empty, Write Bucket C Level
	if(bucks.levels[1] == 0)
	{
		bucket_C_levels.push_back(bucks.levels[3]);
		//std::cout << "Bucket C Level: " << bucks.levels[3] << std::endl;
	}
	
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			if(i != j)
			{
				Buckets poured = fill_buckets(bucks, i, j);
				
				if(poss_fill(bucks, poured, visited))
				{
					std::vector<int> temp = solve(poured, visited);
					bucket_C_levels.insert(bucket_C_levels.end(), temp.begin(), temp.end());
				}
			}
		}
	}
	
	return bucket_C_levels;
}

int main()
{
	std::ifstream filein("milk3.in");
	std::ofstream fileout("milk3.out");
	
	int a; filein >> a;
	int b; filein >> b;
	int c; filein >> c;
	
	Buckets og(a, b, c);
	
	std::vector<Buckets> visited;
	std::vector<int> solution = solve(og, visited);
	
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

