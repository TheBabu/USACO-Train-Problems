"""
ID: ten.to.1
TASK: humble
LANG: PYTHON3
"""

#!/usr/bin/python

from itertools import combinations_with_replacement
import bisect

file_in  = open("humble.in", "r")
file_out = open("humble.out", "w")

K, N = map(int, file_in.readline().split())
P    = list(map(int, file_in.read().split()))
S    = [1]

while(len(S) <= N):
	the_min = 99999999
	
	for s in S:
		for p in P:
			if(s * p not in S):
				the_min = min(the_min, s * p)
	
	S.append(the_min)

file_out.write(str(S[N]) + "\n")

