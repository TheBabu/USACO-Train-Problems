"""
ID: ten.to.1
TASK: runround
LANG: PYTHON3
"""

#!/usr/bin/python

file_in  = open("runround.in", "r")
file_out = open("runround.out", "w")

M = int(file_in.read())

def is_unique(digits):
	for n in range(0, len(digits)):
		for j in range(n + 1, len(digits)):
			if(digits[n] == digits[j]):
				return False
	
	return True

def is_runround(n):
	digits  = [int(x) for x in str(n)]
	touched = [False] * len(digits)
	
	if(not is_unique(digits)):
		return False
	
	for n in digits:
		if(n == 0):
			return False
	
	moves = 0
	
	for n in range(0, len(digits)):
		moves += digits[moves % len(digits)]
		touched[moves % len(digits)] = True
	
	for t in touched:
		if(not t):
			return False
	
	if(digits[moves % len(digits)] == digits[0]):
		return True
	else:
		return False

M += 1
while(not is_runround(M)):
	M += 1

file_out.write(str(M) + "\n")

