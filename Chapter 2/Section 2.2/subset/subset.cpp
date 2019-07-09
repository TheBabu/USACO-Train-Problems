/*
ID: ten.to.1
TASK: subset
LANG: C++
*/

//Implementation by Henri Prudhomme
//Learn how to do!
//Bottom up approach?

#include <iostream>
#include <fstream>

int sum(int N)
{
	int ans = 0;
	
	for(int i = 1; i <= N; i++)
	{
		ans += i;
	}
	
	return ans;
}

int main()
{
	std::ifstream file_in("subset.in");
	std::ofstream file_out("subset.out");
	
	int N; file_in >> N;
	//Sums get extrememly large, so long long required
	long long dp[1000]  = {  };
	long long max_sum    = sum(N);
	long long target_sum = max_sum / 2;
	
	dp[0] = 1;
	
	if(max_sum % 2 == 1)
	{
		file_out << "0\n";
	}
	else
	{
		for(long long i = 1; i <= N; i++) 
		{
			for(long long j = max_sum - i; j >= 0; j--) 
			{
				//The j + i solution just depends on the jth solution of multiple iterations
				//The for loops are the pattern that it follows
				dp[j + i] += dp[j];
				
				/*
				Explanation:
				For example, consider that you want make sum 15.
				At the first step of outer cycle you are using number 1, and there is ways[14] variants to make this sum.
				At the second step of outer cycle you are using number 2, and there is ways[13] new variants to make this sum, you have to add these new variants.
				At the third step of outer cycle you are using number 3, and there is ways[12] new variants to make this sum, you have to add these new variants.
				*/
				
				/*
				std::cout << "(" << j << ", " << j + i << ") ";
				for(int k = 0; k < max_sum; k++)
					std::cout << dp[k] << ' ';
				std::cout << '\n';
				*/
			}
			//std::cout << '\n';
		}
		
		//for(int n : ways)
		//	std::cout << n << ' ';
		
		//ways is possible sums, target sum will always be half of max sum
		//number of pairs possible is half of ways
		file_out << dp[target_sum] / 2 << "\n";
	}
}

