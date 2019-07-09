/*
ID: ten.to.1
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

int main()
{
	std::ifstream gift1in("gift1.in");
	std::ofstream gift1out("gift1.out");
	
	//Variables
	int totalusers; gift1in >> totalusers;
	std::map<std::string, int> userbalances;
	std::vector<std::string> users;
	
	//Create Users and Balances
	std::string user;
	for(int i = 1; i <= totalusers; i++)
	{
		gift1in >> user;
		users.push_back(user);
		userbalances[user] = 0;
	}
	
	//Completing Transactions
	std::string usergiver;
	std::string currrecv;
	while(gift1in >> usergiver)
	{
		int totalmoney; gift1in >> totalmoney;
		int usersrecv; gift1in >> usersrecv;
		int giftmoney = 0;
		//Avoid division by 0
		if(usersrecv != 0)
		{
			giftmoney = totalmoney / usersrecv;
		}
		int leftmoney = totalmoney - (giftmoney * usersrecv);
		
		//Leftover Money
		userbalances[usergiver] +=  leftmoney - totalmoney;
		
		//Give Money
		for(int i = 1; i <= usersrecv; i++)
		{
			gift1in >> currrecv;
			userbalances[currrecv] += giftmoney;
		}
	}
	
	//Write to file
	for(int i = 0; i < totalusers; i++)
	{
		gift1out << users[i] << " " << userbalances[users[i]] << "\n";
	}
}

