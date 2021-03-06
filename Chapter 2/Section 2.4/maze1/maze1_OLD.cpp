/*
ID: ten.to.1
TASK: maze1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

const int MAX_W = 38;
const int MAX_H = 100;

struct Square
{
	Square* adj[4];
	int adj_size = 0;
	int dist     = 99999;
	
	void add_edge(Square* s)
	{
		adj[adj_size] = s;
		adj_size++;
	}
};

bool operator<(const Square& c1, const Square& c2)
{
	return c1.dist < c2.dist;
}

char raw[2 * MAX_H + 1][2 * MAX_W + 1];
Square maze[MAX_H][MAX_W];

Square* visited_1[MAX_H][MAX_W]; int visited_1_size = 0;
Square* visited_2[MAX_H][MAX_W]; int visited_2_size = 0;
std::vector<Square*> queue_1;
std::vector<Square*> queue_2;

bool is_visited(Square* s, Square** visited, const int& visited_size)
{
	for(int i = 0; i < visited_size; i++)
		if(s == visited[i])
			return true;
	
	return false;
}

//Too many stack calls
void solve(Square* curr, Square** visited, int& visited_size, std::vector<Square*>& queue)
{
	visited[visited_size] = curr;
	visited_size++;
	
	for(int i = 0; i < curr->adj_size; i++)
	{
		if(!is_visited(curr->adj[i], visited, visited_size))
		{
			if(curr->dist + 1 <= curr->adj[i]->dist)
			{
				curr->adj[i]->dist = curr->dist + 1;
			}
			
			queue.push_back(curr->adj[i]);
		}
	}
	
	std::sort(queue.begin(), queue.end());
	if(queue.size() > 0)
	{
		Square* s = queue[0];
		queue.erase(queue.begin());
		solve(s, visited, visited_size, queue);
	}
}

int main()
{
	std::ifstream file_in("maze1.in");
	std::ofstream file_out("maze1.out");
	
	int W, H; file_in >> W >> H;
	
	file_in.get();
	for(int i = 0; i < 2 * H + 1; i++)
	{
		for(int j = 0; j < 2 * W + 1; j++)
		{
			raw[i][j] = file_in.get();
		}
		file_in.get();
	}
	
	Square* exits[2];
	int exits_size = 0;
	
	for(int i = 1; i < 2 * H + 1; i += 2)
	{
		for(int j = 1; j < 2 * W + 1; j += 2)
		{
			if(raw[i + 1][j] == ' ')
			{
				//Debug
				//std::cout << "(" << (i - 1) / 2 << ", " << (j - 1) / 2 << ") " << "DOWN\n";
				if(i == 2 * H - 1)
				{
					exits[exits_size] = &maze[(i - 1) / 2][(j - 1) / 2];
					exits_size++;
				}
				else
					
				{
					maze[(i - 1) / 2][(j - 1) / 2].add_edge(&maze[(i - 1) / 2 + 1][(j - 1) / 2]);
				}
			}
			if(raw[i - 1][j] == ' ')
			{
				//Debug
				//std::cout << "(" << (i - 1) / 2 << ", " << (j - 1) / 2 << ") " << "UP\n";
				if(i == 1)
				{
					exits[exits_size] = &maze[(i - 1) / 2][(j - 1) / 2];
					exits_size++;
				}
				else
				{
					maze[(i - 1) / 2][(j - 1) / 2].add_edge(&maze[(i - 1) / 2 - 1][(j - 1) / 2]);
				}
			}
			if(raw[i][j + 1] == ' ')
			{
				//Debug
				//std::cout << "(" << (i - 1) / 2 << ", " << (j - 1) / 2 << ") " << "RIGHT\n";
				if(j == 2 * W - 1)
				{
					exits[exits_size] = &maze[(i - 1) / 2][(j - 1) / 2];
					exits_size++;
				}
				else
				{
					maze[(i - 1) / 2][(j - 1) / 2].add_edge(&maze[(i - 1) / 2][(j - 1) / 2 + 1]);
				}
			}
			if(raw[i][j - 1] == ' ')
			{
				//Debug
				//std::cout << "(" << (i - 1) / 2 << ", " << (j - 1) / 2 << ") " << "LEFT\n";
				if(j == 1)
				{
					exits[exits_size] = &maze[(i - 1) / 2][(j - 1) / 2];
					exits_size++;
				}
				else
				{
					maze[(i - 1) / 2][(j - 1) / 2].add_edge(&maze[(i - 1) / 2][(j - 1) / 2 - 1]);
				}
			}
		}
	}
	
	exits[0]->dist = 1;
	solve(exits[0], &visited_1[0][0], visited_1_size, queue_1);
	
	exits[1]->dist = 1;
	solve(exits[1], &visited_2[0][0], visited_2_size, queue_2);
	
	int max = -1;
	
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W; j++)
		{
			//Debug
			std::cout << maze[i][j].dist << ' ';
			max = std::max(max, maze[i][j].dist);
		}
		//Debug
		std::cout << '\n';
	}
	
	file_out << max << '\n';
}

