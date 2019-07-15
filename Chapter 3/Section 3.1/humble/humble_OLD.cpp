/*
ID: ten.to.1
TASK: humble
LANG: C++
*/

//Help from zzh8829
//https://usacosolutions.wordpress.com/2012/09/30/usaco-3-1-prog-humble/

#include <iostream>
#include <fstream>
#include <set>
#include <map>

const int MAX_K = 100;
const int MAX_N = 100000;

long int P[MAX_K];
std::set<long int> S;

int main()
{
	std::ifstream file_in("humble.in");
	std::ofstream file_out("humble.out");
	
	int K, N; file_in >> K >> N;
	
	for(int i = 0; i < K; i++)
	{
		file_in >> P[i];
		S.insert(P[i]);
	}
	
	std::set<long int>::iterator set_iterator = S.begin();
	for(int n = 0; n < N; n++)
	{
		std::set<long int>::iterator set_end = S.begin(); std::advance(set_end, N - 1);
		bool max_break = false;
		for(int k = 0; k < K; k++)
		{
			long int new_num = P[k] * *set_iterator;
			
			//Debug
			/*
			std::cout << P[k] << " * " << *set_iterator << " = " << new_num << " | size: " << S.size() << " | end: " << *set_end << " | ";
			std::set<long int>::iterator set_iterator_debug = S.begin();
			for(int i = 0; i < N; i++)
			{
				std::cout << *set_iterator_debug << ' ';
				set_iterator_debug++;
			}
			*/
			
			if(new_num < *set_end || S.size() < N)
			{
				int length_prev = S.size();
				S.insert(new_num);
				if(length_prev != S.size())
				{
					if(S.size() == N + 1)
					{
						S.erase(set_end);
					}
					set_end--;
				}
				//std::cout << '\n';
			}
			else
			{
				//std::cout << " BIG\n";
				if(k == 0)
				{
					max_break = true;
				}
				break;
			}
		}
		if(max_break)
			break;
		//std::cout << '\n';
		set_iterator++;
	}
	
	//Debug
	/*
	std::set<long int>::iterator set_iterator_debug = S.begin();
	for(int i = 0; i < N; i++)
	{
		std::cout << *set_iterator_debug << '\n';
		set_iterator_debug++;
	}
	*/
	set_iterator = S.begin();
	std::advance(set_iterator, N - 1);
	file_out << *set_iterator << '\n';
}

