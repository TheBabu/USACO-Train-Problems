/*
ID: ten.to.1
TASK: pprime
LANG: C++
*/

bool is_prime(int n) {
	// Assumes that n is a positive natural number
	// We know 1 is not a prime number
	if (n == 1) {
		return false;
	}
	
	int i = 2;
	// This will loop from 2 to int(sqrt(x))
	while (i*i <= n) {
		// Check if i divides x without leaving a remainder
		if (n % i == 0) {
			// This means that n has a factor in between 2 and sqrt(n)
			// So it is not a prime number
			return false;
		}
		i += 1;
	}
	// If we did not find any factor in the above loop,
	// then n is a prime number
	return true;
}

struct Result
{
	
};

int main()
{
	
}

