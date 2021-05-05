/*
ID: ten.to.1
TASK: butter
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <list>
#include <tuple>
#include <queue>
#include <unordered_map>

const int MAX_P = 801;
int distances[MAX_P][MAX_P];

struct Pasture
{
	int id;
	std::list<std::tuple<Pasture*, int>> adj;
	
	void add_adj(Pasture* pasture, int distance)
	{
		adj.push_back({ pasture, distance });
	}
};

struct Compare
{
	bool operator()(const std::tuple<Pasture*, int> a, const std::tuple<Pasture*, int> b)
	{
		return std::get<1>(a) < std::get<1>(b);
	}
};

void solve(Pasture* start_pasture, int pasture_row)
{
	std::priority_queue<std::tuple<Pasture*, int>, std::vector<std::tuple<Pasture*, int>>, Compare> queue;
	std::unordered_map<Pasture*, bool> visited;
	
	queue.push({ start_pasture, 0 });
	
	while(!queue.empty())
	{
		Pasture* curr_pasture = std::get<0>(queue.top());
		int curr_distance     = std::get<1>(queue.top());
		queue.pop();
		
		//Debug
		//std::cout << curr_pasture->id << '\n';
		//std::cout << queue.size() << '\n';
		
		if(visited[curr_pasture])
			continue;
		visited[curr_pasture] = true;
		
		//Debug
		//std::cout << "ID: " << curr_pasture->id << ' ' << curr_distance <<'\n';
		std::priority_queue<std::tuple<Pasture*, int>, std::vector<std::tuple<Pasture*, int>>, Compare> temp = queue;
		std::cout << "QUEUE:";
		while(!temp.empty())
		{
			std::cout << std::get<1>(queue.top()) << ' ';
			temp.pop();
		}
		std::cout << '\n';
		
		
		for(auto it = curr_pasture->adj.begin(); it != curr_pasture->adj.end(); it++)
		{
			//Debug
			//std::cout << curr_distance + std::get<1>(*it) << ' ' << distances[pasture_row][std::get<0>(*it)->id] << '\n';
			//std::cout << std::get<1>(*it) << '\n';
			
			if(curr_distance + std::get<1>(*it) < distances[pasture_row][std::get<0>(*it)->id])
			{
				
				distances[pasture_row][curr_pasture->id] = curr_distance + std::get<1>(*it);
				
				queue.push({ std::get<0>(*it), distances[pasture_row][curr_pasture->id] });
			}
		}
		
		//Debug
		//std::cout << queue.size() << '\n';
	}
}

int main()
{
	std::ifstream file_in("butter.in");
	std::ofstream file_out("butter.out");
	
	int N, P, C; file_in >> N >> P >> C;
	int pastures_with_cows[N];
	Pasture pastures[P + 1];
	
	//Setup
	for(int i = 0; i < N; i++)
	{
		file_in >> pastures_with_cows[i];
	}
	
	for(int i = 1; i <= P; i++)
	{
		pastures[i].id = i;
		
		for(int j = 1; j <= P; j++)
		{
			if(i == j)
				distances[i][j] = 0;
			else
				distances[i][j] = 99999999;
		}
	}
	
	for(int i = 0; i < C; i++)
	{
		int pasture_a, pasture_b, distance; file_in >> pasture_a >> pasture_b >> distance;
		
		pastures[pasture_a].add_adj(&pastures[pasture_b], distance);
		pastures[pasture_b].add_adj(&pastures[pasture_a], distance);
	}
	
	//Dijkstra’s Algorithm
	solve(&pastures[1], 1);
	
	//Debug
	std::cout << "\nRESULT:\n";
	for(int i = 1; i <= P; i++)
	{
		for(int j = 1; j <= P; j++)
		{
			std::cout << distances[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::list<std::tuple<Pasture*, int>> test = pastures[1].adj;
	for(auto it = test.begin(); it != test.end(); it++)
	{
		std::cout << std::get<1>(*it) << ' ';
	}
}

