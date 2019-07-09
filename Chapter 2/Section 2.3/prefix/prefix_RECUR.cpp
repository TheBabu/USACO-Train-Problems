/*
ID: ten.to.1
TASK: prefix
LANG: C++
*/

//Not good because of amount of stack calls
//https://www.geeksforgeeks.org/tabulation-vs-memoizatation/

#include <iostream>
#include <fstream>

const int MAX_P = 200;
const int MAX_S = 200000;

std::string prims[MAX_P];
std::string sequence;
bool reach[MAX_S];

int solve(int i, int P)
{
	reach[i] = true;
	
	int max = 0;
	
	for(int j = 0; j < P; j++)
	{
		if(prims[j] == sequence.substr(i, prims[j].length()) && !reach[i + prims[j].length()])
		//if(prims[j] == sequence.substr(i, prims[j].length()))
		{
			//Debug
			std::cout << prims[j] << '\n';
			int c = solve(i + prims[j].length(), P);
			
			max = max > c ? max : c;
			
			//Debug
			//std::cout << i << '\n';
		}
	}
	
	return max > i ? max : i;
}

int main()
{
	std::ifstream file_in("prefix.in");
	std::ofstream file_out("prefix.out");
	
	int P = 0;
	std::string inp; file_in >> inp;
	while(inp != ".")
	{
		prims[P] = inp;
		file_in >> inp;
		P++;
	}
	while(!file_in.eof())
	{
		std::string inp; file_in >> inp;
		sequence += inp;
	}
	
	
	file_out << solve(0, P) << '\n';
	
	//Debug
	//for(int i = 0; i < sequence.length(); i++)
	//	std::cout << reach[i] << ' ';
}

