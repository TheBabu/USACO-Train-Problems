/*
ID: ten.to.1
TASK: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
//#include <vector>

struct TriNode
{
	int value;
	TriNode* left;
	TriNode* right;
	
	TriNode()
	{
		
	}
	
	TriNode(int v)
	{
		value = v;
		left  = NULL;
		right = NULL;
	}
};

int sum_fact(int n)
{
	return (n == 0) ? 0 : sum_fact(n - 1) + n;
}

void solve(TriNode* node, int& max, int sum)
{
	sum += node->value;
	
	if(node->left == NULL)
	{
		std::cout << sum << '\n';
		if(max < sum)
		{
			max = sum;
		}
		return;
	}
	
	solve(node->left, max, sum);
	solve(node->right, max, sum);
}

int main()
{
	std::ifstream filein("numtri.in");
	std::ofstream fileout("numtri.out");
	
	int R; filein >> R;
	int num_of_nodes = sum_fact(R);
	TriNode nodes[R][num_of_nodes];
	//std::vector<std::vector<TriNode>> nodes;
	
	for(int i = 0; i < R; i++)
	{
		//std::vector<TriNode> temp;
		for(int j = 0; j < i + 1; j++)
		{
			int v; filein >> v;
			TriNode t(v);
			nodes[i][j] = t;
			
			/*
			int v; filein >>v ;
			TriNode t(v);
			temp.push_back(t);
			*/
		}
		//nodes.push_back(temp);
	}
	
	for(int i = 0; i < (R - 1); i++)
	{
		for(int j = 0; j < i + 1; j++)
		{
			nodes[i][j].left  = &nodes[i + 1][j];
			nodes[i][j].right = &nodes[i + 1][j + 1];
		}
	}
	int max = -1;
	solve(&nodes[0][0], max, 0);
	fileout << max << '\n';
}

