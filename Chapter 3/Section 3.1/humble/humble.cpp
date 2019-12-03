/*
ID: ten.to.1
TASK: humble
LANG: C++
*/

//Implemenation from zzh8829
//https://usacosolutions.wordpress.com/2012/09/30/usaco-3-1-prog-humble/

#include <iostream>
#include <fstream>
#include <set>
 
int P[101];
std::set<int> S;
 
int main()
{
	std::ifstream file_in("humble.in");
	std::ofstream file_out("humble.out");
	
	int K, N; file_in >> K >> N;
	for(int i = 0; i != K ;i++)
	{
		file_in >> P[i];
		S.insert(P[i]);
	}
	
	//Go through each prime once
	for(int i = 0; i != K; i++)
	{
		std::set<int>::iterator S_it = S.begin();
		
		//Keep looping through humble numbers
		while(true)
		{
			//t == new_num
			int t = (*S_it) * P[i];
			
			//Avoid overflow
			if(t < 0)
				break;
			
			if(S.size() > N)
			{
				//Delete last one
				//-- Increment Before then execute command
				S.erase(--S.end());
				
				if(t > (*(--S.end())))
					break;
			}
			
			//Insert only if t is less than max range
			S.insert(t);
			S_it++;
		}
	}
	
	file_out << *(--S.end()) << '\n';
}
