"""
ID: ten.to.1
LANG: PYTHON3
TASK: gift1
"""

#!/usr/bin/python
#Attempt to hardcore more values? More local?

gift1in   = open("gift1.in", "r")
gift1out  = open("gift1.out", "w")
translist = gift1in.read().split()

def CreateUsers(translist):
	users = {}
	
	#Create Users
	for i in range(1, int(translist[0]) + 1):
		users[translist[i]] = 0
	#Pop Elements
	for i in range(0, int(translist[0]) + 1):
		translist.pop(0)
	
	return users

def GiveMoney(users, translist):
	while (len(translist) != 0):
		#Deduce Amount
		curruser = translist[0]
		translist.pop(0)
		users[curruser] += -(int(translist[0]))
		
		#Give Amount
		amtofreci = int(translist[1])
		if(amtofreci != 0): giftmon = int(int(translist[0]) / amtofreci)
		keepmon = int(int(translist[0]) - giftmon * amtofreci)
		
		for i in range(0, 2):
			translist.pop(0)
		
		users[curruser] += keepmon
		
		for i in range(0, amtofreci): 
			users[translist[0]] += giftmon
			translist.pop(0)

def WriteMap(file, map):
	for i in map:
		write = str(i) + " " + str(map[i]) + "\n"
		file.write(write)

users = CreateUsers(translist)
GiveMoney(users, translist)
WriteMap(gift1out, users)

