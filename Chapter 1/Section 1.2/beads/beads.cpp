/*
ID: ten.to.1
LANG: C++
TASK: beads
*/

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream beadsin("beads.in");
	std::ofstream beadsout("beads.out");
	
	//Variables
	int numofbeads; beadsin >> numofbeads;
	char beads[numofbeads]; 
	
	//Input Beads to Array
	char inpbead;
	for(int i = 0; i <= numofbeads; i++)
	{
		beadsin >> inpbead;
		beads[i] = inpbead;
	}
	
	/*
	PROBABLY EASIER IN PYTHON
	*/
}

