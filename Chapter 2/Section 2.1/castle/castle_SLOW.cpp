/*
ID: ten.to.1
TASK: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

#define Bit std::bitset<4>

struct Room
{
	Bit walls;
	std::vector<Room*> adj;
	
	Room& operator=(const Bit& bit)
	{
		walls = bit;
		return *this;
	}
	
	void add_edge(Room* r)
	{
		adj.push_back(r);
	}
};

bool is_visited(Room* r, const std::vector<Room*>& visited)
{
	for(int i = 0; i < visited.size(); i++)
	{
		if(visited[i] == r)
			return true;
	}

	return false;
}

void dfs(Room* r, std::vector<Room*>& visited)
{
	visited.push_back(r);
	
	//std::cout << r << "\n";
	
	for(int i = 0; i < r->adj.size(); i++)
	{
		if(!is_visited(r->adj[i], visited))
		{
			dfs(r->adj[i], visited);
		}
	}
}

int main()
{
	std::ifstream file_in("castle.in");
	std::ofstream file_out("castle.out");
	
	int M; file_in >> M; //Column
	int N; file_in >> N; //Row
	Room castle[N][M];

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			int r; file_in >> r;
			castle[i][j] = r;
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			//std::cout << &castle[i][j] << ' ';
			//0 W
			if(!castle[i][j].walls.test(0))
				castle[i][j].add_edge(&castle[i][j - 1]);
			//1 N
			if(!castle[i][j].walls.test(1))
				castle[i][j].add_edge(&castle[i - 1][j]);
			//2 E
			if(!castle[i][j].walls.test(2))
				castle[i][j].add_edge(&castle[i][j + 1]);
			//3 S
			if(!castle[i][j].walls.test(3))
				castle[i][j].add_edge(&castle[i + 1][j]);
		}
		//std::cout << '\n';
	}
	
	int num_rooms    = 0;
	int prev         = 0;
	int size_largest = 0;
	
	std::vector<Room*> visited;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(!is_visited(&castle[i][j], visited))
			{
				num_rooms++;
				
				dfs(&castle[i][j], visited);
				
				size_largest = ((visited.size() - prev) > size_largest) ? (visited.size() - prev) : size_largest;
				prev         = visited.size();
			}
		}
	}
	
	//Break Wall
	//North
	int break_largest_north = 0;
	int x_loc_north         = 0;
	int y_loc_north         = 0;
	
	for(int i = N - 1; i >= 1; i--)
	{
		for(int j = 0; j < M; j++)
		{
			visited.clear();
			
			if(castle[i][j].walls.test(1))
			{
				castle[i][j].add_edge(&castle[i - 1][j]);
				castle[i - 1][j].add_edge(&castle[i][j]);
				
				dfs(&castle[i][j], visited);
				
				if(visited.size() > break_largest_north)
				{
					break_largest_north = visited.size();
					x_loc_north         = i + 1;
					y_loc_north         = j + 1;
				}
				
				castle[i][j].adj.pop_back();
				castle[i - 1][j].adj.pop_back();
			}
		}
	}
	
	//East
	int break_largest_east = 0;
	int x_loc_east         = 0;
	int y_loc_east         = 0;
	
	for(int i = N - 1; i >= 0; i--)
	{
		for(int j = 0; j < M - 1; j++)
		{
			visited.clear();
			
			if(castle[i][j].walls.test(2))
			{
				
				castle[i][j].add_edge(&castle[i][j + 1]);
				castle[i][j + 1].add_edge(&castle[i][j]);
				
				dfs(&castle[i][j], visited);
				
				if(visited.size() > break_largest_east)
				{
					break_largest_east = visited.size();
					x_loc_east         = i + 1;
					y_loc_east         = j + 1;
				}
				
				castle[i][j].adj.pop_back();
				castle[i][j + 1].adj.pop_back();
			}
		}
	}
	
	//std::cout << break_largest_north << ' ' << x_loc_north << ' ' << y_loc_north << '\n';
	//std::cout << break_largest_east << ' ' << x_loc_east << ' ' << y_loc_east << '\n';
	
	file_out << num_rooms << '\n' << size_largest << '\n';
	if(break_largest_north == break_largest_east)
	{
		if(y_loc_north <= y_loc_east)
		{
			file_out << break_largest_north << '\n' << x_loc_north << ' ' << y_loc_north << " N\n";
		}
		else
		{
			file_out << break_largest_east << '\n' << x_loc_east << ' ' << y_loc_east << " E\n";
		}
	}
	else if(break_largest_north > break_largest_east)
	{
		file_out << break_largest_north << '\n' << x_loc_north << ' ' << y_loc_north << " N\n";
	}
	else
	{
		file_out << break_largest_east << '\n' << x_loc_east << ' ' << y_loc_east << " E\n";
	}
}
