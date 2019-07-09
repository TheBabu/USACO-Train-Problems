"""
ID: ten.to.1
TASK: zerosum
LANG: PYTHON3
"""

#!/usr/bin/python

file_in  = open("zerosum.in", "r")
file_out = open("zerosum.out", "w")

N = int(file_in.read())

choose = [" ", "+", "-"]

def solve(b, n):
	if(n == N):
		b += str(N)
		if(eval(b.replace(" ", "")) == 0):
			file_out.write(b + "\n")
		return
	
	for c in choose:
		solve(b + str(n) + c, n + 1)

solve("", 1)

