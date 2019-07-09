/*
ID: ten.to.1
TASK: agrinet
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

const int MAX_N = 100;

int adj[MAX_N][MAX_N];

int main()
{
	std::ifstream file_in("agrinet.in");
	std::ofstream file_out("agrinet.out");
	
	int N; file_in >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			file_in >> adj[i][j];
	
	int sum = 0;
	
	bool visited[MAX_N] = { };
	std::vector<std::tuple<int, int>> queue;
	for(int i = 0; i < N; i++)
		queue.push_back(std::make_tuple(i, adj[0][i]));
	visited[0] = true;
	
	while(true)
	{
		std::tuple<int, int> min = std::make_tuple(1000000, 1000000);
		int queue_size = queue.size();
		for(int i = queue_size - 1; i >= 0; i--)
		{
			//Debug
			//std::cout << std::get<0>(queue[i]) << ' ' << std::get<1>(queue[i]) << '\n';
			
			if(visited[std::get<0>(queue[i])])
			{
				//Debug
				//std::cout << std::get<0>(queue[i]) << ' ' << std::get<1>(queue[i]) << '\n';
				
				queue.erase(queue.begin() + i);
			}
			else if(std::get<1>(queue[i]) < std::get<1>(min))
			{
				min = queue[i];
			}
		}
		//Debug
		//std::cout << '\n';
		
		sum += std::get<1>(min);
		visited[std::get<0>(min)] = true;
		for(int i = 0; i < N; i++)
			queue.push_back(std::make_tuple(i, adj[std::get<0>(min)][i]));
		
		bool stop = true;
		for(int i = 0; i < N; i++)
		{
			if(!visited[i])
			{
				stop = false;
				break;
			}
		}
		
		if(stop)
			break;
	}
	
	file_out << sum << '\n';
}

