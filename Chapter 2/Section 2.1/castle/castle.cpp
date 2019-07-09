/*
ID: ten.to.1
TASK: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <bitset>
#include <array>

#define Bit std::bitset<4>

struct Room
{
	Bit walls;
	std::array<Room*, 4> adj;
	int adj_size = 0;
	int room_id;
	int room_val;
	
	Room& operator=(const Bit& bit)
	{
		walls = bit;
		return *this;
	}
	
	void add_edge(Room* r)
	{
		adj[adj_size] = r;
		adj_size++;
	}
};

bool is_visited(Room* r, const std::array<Room*, 2500>& visited, int& visited_size)
{
	for(int i = 0; i < visited_size; i++)
	{
		if(visited[i] == r)
			return true;
	}

	return false;
}

void dfs(Room* r, std::array<Room*, 2500>& visited, int& visited_size)
{
	visited[visited_size] = r;
	visited_size++;
	
	//std::cout << r << "\n";
	
	for(int i = 0; i < r->adj_size; i++)
	{
		if(!is_visited(r->adj[i], visited, visited_size))
		{
			dfs(r->adj[i], visited, visited_size);
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
	
	//std::cout << "INSERT DATA\n";
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			int r; file_in >> r;
			castle[i][j] = r;
		}
	}
	
	//std::cout << "CONNECT ROOMS\n";
	
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
	
	//std::cout << "DEFAULT DFS\n";
	
	int num_rooms    = 0;
	int prev         = 0;
	int size_largest = 0;
	
	std::array<Room*, 2500> visited;
	int room_id      = 1;
	int visited_size = 0;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(!is_visited(&castle[i][j], visited, visited_size))
			{
				num_rooms++;
				
				dfs(&castle[i][j], visited, visited_size);
				
				size_largest = ((visited_size - prev) > size_largest) ? (visited_size - prev) : size_largest;
				for(int i = prev; i < visited_size; i++)
				{
					visited[i]->room_id  = room_id;
					visited[i]->room_val = visited_size - prev;
				}
				prev = visited_size;
				room_id++;
			}
		}
	}
	
	/*
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			std::cout << castle[i][j].room_val << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			std::cout << castle[i][j].room_id << ' ';
		}
		std::cout << '\n';
	}
	*/
	//std::cout << "BREAK WALL\n";
	
	//Break Wall
	//North
	int break_largest_north = 0;
	int x_loc_north         = 0;
	int y_loc_north         = 0;
	
	for(int j = 0; j < M; j++)
	{
		for(int i = N - 1; i >= 1; i--)
		{
			if(castle[i][j].walls.test(1) && castle[i][j].room_id != castle[i - 1][j].room_id)
			{
				//std::cout << "N: " << i + 1 << ' ' << j + 1 << " | " << castle[i][j].room_val << " + " << castle[i - 1][j].room_val << " = " << castle[i][j].room_val +  castle[i - 1][j].room_val << '\n';
				if(castle[i][j].room_val + castle[i - 1][j].room_val > break_largest_north)
				{
					break_largest_north = castle[i][j].room_val + castle[i - 1][j].room_val;
					x_loc_north         = i + 1;
					y_loc_north         = j + 1;
				}
			}
		}
	}
	
	//East
	int break_largest_east = 0;
	int x_loc_east         = 0;
	int y_loc_east         = 0;
	
	for(int j = 0; j < M - 1; j++)
	{
		for(int i = N - 1; i >= 0; i--)
		{
			if(castle[i][j].walls.test(2) && castle[i][j].room_id != castle[i][j + 1].room_id)
			{
				//std::cout << "E: " << i + 1 << ' ' << j + 1 << " | " << castle[i][j].room_val << " + " << castle[i][j + 1].room_val << " = " << castle[i][j].room_val +  castle[i][j + 1].room_val << '\n';
				if(castle[i][j].room_val + castle[i][j + 1].room_val > break_largest_east)
				{
					break_largest_east = castle[i][j].room_val + castle[i][j + 1].room_val;
					x_loc_east         = i + 1;
					y_loc_east         = j + 1;
				}
			}
		}
	}
	
	//std::cout << break_largest_north << ' ' << x_loc_north << ' ' << y_loc_north << '\n';
	//std::cout << break_largest_east << ' ' << x_loc_east << ' ' << y_loc_east << '\n';
	
	//std::cout << "OUTPUT ANS\n";
	
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

