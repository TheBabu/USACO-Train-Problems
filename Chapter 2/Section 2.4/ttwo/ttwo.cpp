/*
ID: ten.to.1
TASK: ttwo
LANG: C++
*/

#include <iostream>
#include <fstream>

char grid[10][10];

int main()
{
	std::ifstream file_in("ttwo.in");
	std::ofstream file_out("ttwo.out");
	
	int F_x;
	int F_y;
	int C_x;
	int C_y;
	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			char c = file_in.get();
			grid[i][j] = c;
			
			if(c == 'F')
			{
				F_x = i;
				F_y = j;
			}
			else if(c == 'C')
			{
				C_x = i;
				C_y = j;
			}
		}
		file_in.get();
	}
	
	int F_d   = 0;
	int C_d   = 0;
	int count = 0;
	bool found = false;
	
	for(int i = 0; i < 1000; i++)
	{
		//std::cout << "F: " << F_x << " " << F_y << '\n';
		//std::cout << "C: " << C_x << " " << C_y << '\n';
		
		//Farmer
		if(F_d % 4 == 0)
		{
			if(grid[F_x - 1][F_y] == '*' || F_x == 0)
			{
				F_d++;
			}
			else
			{
				F_x--;
			}
		}
		else if(F_d % 4 == 1)
		{
			if(grid[F_x][F_y + 1] == '*' || F_y == 9)
			{
				F_d++;
			}
			else
			{
				F_y++;
			}
		}
		else if(F_d % 4 == 2)
		{
			if(grid[F_x + 1][F_y] == '*' || F_x == 9)
			{
				F_d++;
			}
			else
			{
				F_x++;
			}
		}
		else
		{
			if(grid[F_x][F_y - 1] == '*' || F_y == 0)
			{
				F_d++;
			}
			else
			{
				F_y--;
			}
		}
		
		//Cow
		if(C_d % 4 == 0)
		{
			if(grid[C_x - 1][C_y] == '*' || C_x == 0)
			{
				C_d++;
			}
			else
			{
				C_x--;
			}
		}
		else if(C_d % 4 == 1)
		{
			if(grid[C_x][C_y + 1] == '*' || C_y == 9)
			{
				C_d++;
			}
			else
			{
				C_y++;
			}
		}
		else if(C_d % 4 == 2)
		{
			if(grid[C_x + 1][C_y] == '*' || C_x == 9)
			{
				C_d++;
			}
			else
			{
				C_x++;
			}
		}
		else
		{
			if(grid[C_x][C_y - 1] == '*' || C_y == 0)
			{
				C_d++;
			}
			else
			{
				C_y--;
			}
		}
		
		count++;
		
		//Check
		if(F_x == C_x && F_y == C_y)
		{
			found = true;
			break;
		}
		
	}
	
	if(found)
		file_out << count << '\n';
	else
		file_out << "0\n";
}

