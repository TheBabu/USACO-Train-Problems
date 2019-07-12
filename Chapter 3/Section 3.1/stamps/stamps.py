"""
ID: ten.to.1
TASK: stamps
LANG: PYTHON3
"""

#!/usr/bin/python

#Naive solution

from itertools import combinations_with_replacement

file_in  = open("stamps.in", "r")
file_out = open("stamps.out", "w")

MAX_V = 1000000

K, N   = map(int, file_in.readline().split())
stamps = list(map(int, file_in.read().split()))
dp     = [False] * MAX_V
hits   = [MAX_V] * MAX_V

for s in stamps:
	dp[s]   = True
	hits[s] = 1

min_v = min(stamps)
max_v = max(stamps) * K


max_streak = 0
streak     = 0
for i in range(min_v, max_v + 1):
	if(dp[i]):
		streak += 1
		
		for n in range(0, N):
			if(hits[i] < K):
				dp[i + stamps[n]] = True
				hits[i + stamps[n]] = min(hits[i + stamps[n]], hits[i] + 1)
	else:
		max_streak = max(max_streak, streak)
		streak = 0

max_streak = max(max_streak, streak)

file_out.write(str(max_streak) + "\n")

#Debug
#for n in range(min_v, max_v + 1):
#	print(dp[n], end=" ")
#print()
#for n in range(min_v, max_v + 1):
#	print(hits[n], end=" ")

