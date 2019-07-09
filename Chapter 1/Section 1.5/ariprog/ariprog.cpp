/*
ID: ten.to.1
TASK: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream filein("ariprog.in");
	std::ofstream fileout("ariprog.out");
	
	int N; filein >> N;
	int M; filein >> M;
	
	int max_num = (M * M) + (M * M) + 1;
	bool bisquares[max_num];
	int max_n = max_num / (N - 1);
	
	//Create bisquares
	int count = 0;
	for(int i = 0; i < max_num; i++)
	{
		bisquares[i] = false;
	}
	for(int i = 0; i <= M; i++)
	{
		for(int j = 0; j <= M; j++)
		{
			bisquares[(i * i) + (j * j)] = true;
			count++;
		}
	}
	
	//Print bisquares
	/*
	for(int i = 0; i < max_num; i++)
	{
		std::cout << i << ' ' << bisquares[i] << '\n';
	}
	*/
	
	//Solve
	std::vector<int> start_sol;
	std::vector<int> n_sol;
	for(int n = 1; n <= max_n; n++)
	{
		for(int j = 0; j < (max_num - (N - 1) * n); j++)
		{
			bool is_sol = true;
			//std::cout << "n: " << n << " j: " << j << '\n';
			for(int k = 0; k <= (N - 1); k++)
			{
				
				//std::cout << "[" << j + (k * n) << " B?: " << bisquares[ j + (k * n)] << "] ";
				if(!(bisquares[j + (k * n)]))
				{
					is_sol = false;
					break;
				}
			}
			//std::cout << "\n\n";
			
			if(is_sol)
			{
				start_sol.push_back(j);
				n_sol.push_back(n);
			}
		}
	}
	
	//Output
	if(start_sol.size() == 0)
	{
		fileout << "NONE\n";
	}
	
	for(int i = 0; i < start_sol.size(); i++)
	{
		fileout << start_sol[i] << ' ' << n_sol[i] << '\n';
	}
}

