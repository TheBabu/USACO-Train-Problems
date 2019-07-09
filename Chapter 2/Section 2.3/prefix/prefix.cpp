/*
ID: ten.to.1
TASK: prefix
LANG: C++
*/

//Help from daddy Kevin

#include <iostream>
#include <fstream>

const int MAX_P = 200;

std::string prims[MAX_P];
std::string sequence;

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
	bool reach[sequence.length() + 1];
	for(int i = 0; i <= sequence.length(); i++)
		reach[i] = false;
	reach[0] = true;
	
	int max = 0;
	
	
	//Debug
	/*
	for(int i = 0; i <= sequence.length(); i++)
		std::cout << reach[i] << ' ';
	std::cout << '\n';
	*/
	
	for(int i = 0; i <= sequence.length(); i++)
	{
		if(reach[i])
		{
			for(int j = 0; j < P; j++)
			{
				if(prims[j] == sequence.substr(i, prims[j].length()) && !reach[i + prims[j].length()])
				{
					reach[i + prims[j].length()] = true;
					max                          = max > i + prims[j].length() ? max : i + prims[j].length();
					
					//Debug
					/*
					std::cout << prims[j] << '\n';
					for(int i = 0; i <= sequence.length(); i++)
						std::cout << reach[i] << ' ';
					std::cout << '\n';
					*/
				}
			}
		}
	}
	
	file_out << max << '\n';
}

