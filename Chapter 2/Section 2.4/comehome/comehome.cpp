/*
ID: ten.to.1
TASK: comehome
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

const int MAX_D = 99999999;

struct Pasture
{
	std::vector<std::tuple<Pasture*, int>> adj;
	int dist = MAX_D;
	
	void add_edge(Pasture* s, int d)
	{
		adj.push_back(std::make_tuple(s, d));
	}
};

bool is_visited(const Pasture* p, const std::vector<Pasture*>& visited)
{
	for(int i = 0; i < visited.size(); i++)
		if(p == visited[i])
			return true;
	
	return false;
}

void solve(Pasture* p)
{
	std::vector<Pasture*> queue;
	std::vector<Pasture*> visited;
	p->dist = 0;
	queue.push_back(p);
	
	while(!queue.empty())
	{
		int min_index = 0;
		int min       = MAX_D;
		for(int i = 0; i < queue.size(); i++)
		{
			if(queue[i]->dist < min)
			{
				min       = queue[i]->dist;
				min_index = i;
			}
		}
		
		Pasture* u = queue[min_index];
		queue.erase(queue.begin() + min_index);
		visited.push_back(u);
		
		for(int i = 0; i < u->adj.size(); i++)
		{
			if(!is_visited(std::get<0>(u->adj[i]), visited))
			{
				if(u->dist + std::get<1>(u->adj[i]) < std::get<0>(u->adj[i])->dist)
				{
					std::get<0>(u->adj[i])->dist = u->dist + std::get<1>(u->adj[i]); 
				}
				
				//Not in Queue
				if(!is_visited(std::get<0>(u->adj[i]), queue))
				{
					queue.push_back(std::get<0>(u->adj[i]));
				}
			}
		}
	}
}

Pasture pastures[58];

int main()
{
	std::ifstream file_in("comehome.in");
	std::ofstream file_out("comehome.out");
	
	int P; file_in >> P;
	for(int i = 0; i < P; i++)
	{
		char from, to; file_in >> from >> to;
		int dist; file_in >> dist;
		
		pastures[from - 65].add_edge(&pastures[to - 65], dist);
		pastures[to - 65].add_edge(&pastures[from - 65], dist);
	}
	
	solve(&pastures[25]);
	
	int min   = MAX_D;
	int index = -1;
	
	for(int i = 0; i < 25; i++)
	{
		if(pastures[i].dist < min)
		{
			min   = pastures[i].dist;
			index = i;
		}
		
		//Debug
		//std::cout << (char) (i + 65) << ' ' << pastures[i].dist << '\n';
	}
	
	file_out << (char) (index + 65) << ' ' << min << '\n';
}

