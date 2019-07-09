#include <iostream>
#include <fstream>

/*
ID: ten.to.1
LANG: C++
TASK: milk2
*/

bool check_state(int current_time, int range_times[][2], int domain)
{
	for(int i = 0; i <= domain; i++)
	{
		if(current_time >= range_times[i][0] && current_time < range_times[i][1])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	std::ifstream filein("milk2.in");
	std::ofstream fileout("milk2.out");
	
	int domain; filein >> domain;
	int range_times[domain][2];
	int min_time = 1000000;
	int max_time = 0;
	
	for(int i = 0; i <= domain; i++)
	{
		int start_time; filein >> start_time;
		int end_time; filein >> end_time;
		
		range_times[i][0] = start_time;
		range_times[i][1] = end_time;
		
		if(start_time < min_time)
		{
			min_time = start_time;
		}
		
		if(end_time > max_time)
		{
			max_time = end_time;
		}
	}
	
	//for(auto i : range_times) { std::cout << i[0] << ' ' << i[1] << '\n'; };
	//std::cout << min_time << ' ' << max_time;
	
	int longest_work_time = 0;
	int longest_idle_time = 0;
	
	int current_work_time = 0;
	int current_idle_time = 0;
	
	for(int current_time = min_time; current_time <= max_time; current_time++)
	{
		if(check_state(current_time, range_times, domain))
		{
			current_work_time++;
			
			if(current_idle_time > longest_idle_time)
			{
				longest_idle_time = current_idle_time;
			}
			current_idle_time = 0;
		}
		else
		{
			current_idle_time++;
			
			if(current_work_time > longest_work_time)
			{
				longest_work_time = current_work_time;
			}
			current_work_time = 0;
		}
	}
	
	fileout << longest_work_time << ' ' << longest_idle_time << '\n';
}

