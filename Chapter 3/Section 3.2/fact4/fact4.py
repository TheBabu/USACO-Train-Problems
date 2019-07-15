"""
ID: ten.to.1
TASK: fact4
LANG: PYTHON3
"""

#!/usr/bin/python

#Naive solution seems to work!

import math

file_in  = open("fact4.in", "r")
file_out = open("fact4.out", "w")

N         = int(file_in.read())
factorial = str(math.factorial(N))

for n in range(len(factorial) - 1, 0, -1):
	if(factorial[n] != "0"):
		file_out.write(factorial[n] + "\n")
		break

if(len(factorial) == 1):
	file_out.write(factorial + "\n")

