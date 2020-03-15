/*
ID: ten.to.1
TASK: kimbits
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <bitset>

const int MAX_N = 31;
typedef std::bitset<MAX_N> Bitset;

Bitset add_bit(Bitset b, const int& N)
{
	for(int i = 0; i <= N; i++)
	{
		if(!b.test(i))
		{
			b.flip(i);
			return b;
		}
	}
}

Bitset shift_bit_right(Bitset b, const int& N)
{
	for(int i = 0; i < N; i++)
	{
		if(b.test(i) && !b.test(i + 1))
		{
			b.flip(i);
			b.flip(i + 1);
			return b;
		}
	}
}

Bitset shift_bit_left(Bitset b, const int& N)
{
	for(int i = N; i > 0; i--)
	{
		if(!b.test(i) && b.test(i - 1))
		{
			b.flip(i);
			b.flip(i - 1);
			return b;
		}
	}
}

Bitset solve(Bitset string, const int& N, const int& L, const int& I, int& C)
{
	//Debug
	std::cout << string << ' ' << string.to_ulong() << ' ' << C << '\n';
	
	Bitset add         = add_bit(string, N);
	Bitset shift_right = shift_bit_right(string, N);
	Bitset shift_left  = shift_bit_left(string, N);
	Bitset temp;
	
	//Debug
	//std::cout << '\t' << add.to_ulong() << ' ' << shift_right.to_ulong() << ' ' << shift_left.to_ulong() << '\n';
	
	if(C == I)
	{
		return string;
	}
	else if(string.count() >= L)
	{
		return Bitset();
	}
	else if(shift_right.to_ulong() <= shift_left.to_ulong() && shift_right.to_ulong() <= add.to_ulong())
	{
		//Debug
		std::cout << "\t RIGHT\n";
		C++;
		temp = solve(shift_right, N, L, I, C);
		
		
		if(temp == Bitset())
		{
			if(shift_left.to_ulong() < add.to_ulong())
			{
				//Debug
				std::cout << "\t LEFT\n";
				C++;
				temp = solve(shift_left, N, L, I, C);
				
				if(temp == Bitset())
				{
					//Debug
					std::cout << "\t ADD\n";
					C++;
					temp = solve(add, N, L, I, C);
				}
				else
				{
					return temp;
				}
			}
			else
			{
				//Debug
				std::cout << "\t ADD\n";
				C++;
				temp = solve(add, N, L, I, C);
				
				if(temp == Bitset())
				{
					//Debug
					std::cout << "\t LEFT\n";
					C++;
					temp = solve(shift_left, N, L, I, C);
				}
				else
				{
					return temp;
				}
			}
		}
		else
		{
			return temp;
		}
	}
	else if(shift_left.to_ulong() <= shift_right.to_ulong() && shift_left.to_ulong() <= add.to_ulong())
	{
		//Debug
		std::cout << "\t LEFT\n";
		C++;
		temp = solve(shift_left, N, L, I, C);
		
		if(temp == Bitset())
		{
			if(shift_right.to_ulong() < shift_left.to_ulong())
			{
				//Debug
				std::cout << "\t RIGHT\n";
				C++;
				temp = solve(shift_right, N, L, I, C);
				
				if(temp == Bitset())
				{
					//Debug
					std::cout << "\t ADD\n";
					C++;
					temp = solve(add, N, L, I, C);
				}
				else
				{
					return temp;
				}
			}
			else
			{
				//Debug
				std::cout << "\t ADD\n";
				C++;
				temp = solve(add, N, L, I, C);
				
				if(temp == Bitset())
				{
					//Debug
					std::cout << "\t RIGHT\n";
					C++;
					temp = solve(shift_right, N, L, I, C);
				}
				else
				{
					return temp;
				}
			}
		}
		else
		{
			return temp;
		}
	}
	else
	{
		//Debug
		std::cout << "\t ADD\n";
		C++;
		temp = solve(add, N, L, I, C);
		
		if(temp == Bitset())
		{
			if(shift_left.to_ulong() < shift_right.to_ulong())
			{
				//Debug
				std::cout << "\t LEFT\n";
				C++;
				temp = solve(shift_left, N, L, I, C);
				
				if(temp == Bitset())
				{
					//Debug
					std::cout << "\t RIGHT\n";
					C++;
					temp = solve(shift_right, N, L, I, C);
				}
				else
				{
					return temp;
				}
			}
			else
			{
				//Debug
				std::cout << "\t RIGHT\n";
				C++;
				temp = solve(shift_right, N, L, I, C);
				
				if(temp == Bitset())
				{
					//Debug
					std::cout << "\t LEFT\n";
					C++;
					temp = solve(shift_left, N, L, I, C);
				}
				else
				{
					return temp;
				}
			}
		}
		else
		{
			return temp;
		}
	}
}

int main()
{
	std::ifstream file_in("kimbits.in");
	std::ofstream file_out("kimbits.out");
	
	int N, L, I; file_in >> N >> L >> I;
	Bitset string; string.flip(0);
	
	int C = 1;
	solve(string, N, L, I, C);
	
	std::cout << string << '\n';
	std::cout << shift_bit_right(string, N) << '\n';
	std::cout << shift_bit_left(string, N);
}

