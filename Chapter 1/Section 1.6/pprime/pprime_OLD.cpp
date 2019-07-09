/*
ID: ten.to.1
TASK: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool prime(int n)
{
	bool isPrime = true;
	
	for(int i = 2; i <= n / 2; ++i)
	{
		if(n % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	
	return isPrime;
}

int createPalindrome(int input, int b, bool isOdd) 
{ 
	int n = input; 
	int palin = input; 
	
	// checks if number of digits is odd or even 
	// if odd then neglect the last digit of input in 
	// finding reverse as in case of odd number of 
	// digits middle element occur once 
	if (isOdd) 
		n /= b; 
	
	// Creates palindrome by just appending reverse 
	// of number to itself 
	while (n > 0) 
	{ 
		palin = palin * b + (n % b); 
		n /= b; 
	} 
	return palin; 
} 

int main()
{
	std::ifstream filein("pprime.in");
	std::ofstream fileout("pprime.out");
	int A; filein >> A;
	int B; filein >> B;
	std::vector<int> primes;
	
	int number; 
	// Run two times for odd and even length palindromes 
	for (int j = 0; j < 2; j++) 
	{ 
		// Creates palindrome numbers with first half as i.  
		// Value of j decided whether we need an odd length 
		// of even length palindrome. 
		int i = 1; 
		while ((number = createPalindrome(i, 10, j % 2)) < B) 
		{ 
			if(prime(number) && number >= A)
			{
				primes.push_back(number);
			}
			i++; 
		} 
	} 
	
	std::sort(primes.begin(), primes.end());
	for(int i = 0; i < primes.size(); i ++)
	{
		fileout << primes[i] << '\n';
	}
}

