"""
ID: ten.to.1
TASK: humble
LANG: PYTHON3
"""

#!/usr/bin/python

#Help from zzh8829
#https://usacosolutions.wordpress.com/2012/09/30/usaco-3-1-prog-humble/

from itertools import combinations_with_replacement
import bisect

file_in  = open("humble.in", "r")
file_out = open("humble.out", "w")

K, N   = map(int, file_in.readline().split())
P      = list(map(int, file_in.read().split()))
S      = P.copy()
values = { }

for p in P:
	values[p] = True

for p in P:
	for n in range(0, N):
		new_num = p * S[n]
		
		if(values.get(new_num)):
			continue
		
		if(len(S) < N):
			bisect.insort(S, new_num)
			values[new_num] = True
		elif(new_num < S[-1]):
			bisect.insort(S, new_num)
			values[new_num] = True


file_out.write(str(S[N - 1]) + "\n")

