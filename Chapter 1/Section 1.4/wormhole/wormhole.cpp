/*
ID: ten.to.1
TASK: wormhole
LANG: C++
*/

//Implementation by Brian Deen
//(Learn how to do these fluently!)

#include <iostream>
#include <fstream>

//Global variables will always be set to 0
//Indexing of 1
//N == number of wormhole locations
int N, X[13], Y[13], partner[13], next_to_right[13];

//Start at a pos, teleport, move to right, pos...
bool cycle_exists()
{
	for(int start = 1; start <= N; start++)
	{
		//Change current hole to new start
		int curr_hl = start;
		
		//Iterate over N times to make sure that a next_to_right is != 0
		for(int i = 0; i < N; i++)
		{
			//If 0 will stay 0
			curr_hl = next_to_right[partner[curr_hl]];
		}
		
		if(curr_hl != 0)
		{
			return true;
		}
	}
	
	return false;
}

int solve()
{
	//Indexing starts at 1
	int i     = 1;
	int total = 0;
	
	//partner 1, 2, 3, 4...
	//        2, 1, 4, 3...
	//Increase i until not paired (triggers if code block)
	for(; i <= N; i++)
	{
		if(partner[i] == 0)
		{
			break;
		}
	}
	
	//Check if all paired, check if it is possible solution
	if(i > N)
	{
		if(cycle_exists())
		{
			//total += 1
			return 1;
		}
		else
		{
			//total += 0
			return 0;
		}
	}
	
	//Pair i with j
	//i + 1 is next possible pairing wormhole
	for(int j = i + 1; j <= N; j++)
	{
		//If unpaired
		if(partner[j] == 0)
		{
			//Pair them
			partner[i] = j;
			partner[j] = i;
			
			//Recursive, until all paired, then return either 0 or 1
			total += solve();
			
			//Since it is recursive it will make all partners 0,0,0,0...
			partner[i] = 0; 
			partner[j] = 0;
		}
	}
	
	//Only occurs in main solve()
	return total;
}

void create_next_to_right()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			//Check if i can walk to j
			if(X[j] > X[i] && Y[i] == Y[j])
			{
				//If it has no right hole, or the (distance between current X corr of j hole) is less than (distance between previous X coor of the hole to the right of hole i)
				if(next_to_right[i] == 0 || (X[j] - X[i]) < (X[next_to_right[i]] - X[i]))
				{
					next_to_right[i] = j;
				}
			}
		}
	}
}

int main()
{
	std::ifstream filein("wormhole.in");
	std::ofstream fileout("wormhole.out");
	
	filein >> N;
	
	//1..N 
	//1 x1 y1
	//2 x2 y2
	//3 x3 y3
	//4 x3 y 4...
	for(int i = 1; i <= N; i++)
	{
		filein >> X[i] >> Y[i];
	}
	
	//Create next_to_right
	create_next_to_right();
	
	//Output
	fileout << solve() << "\n";
}

