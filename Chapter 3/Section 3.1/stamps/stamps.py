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

K, N   = map(int, file_in.readline().split())
stamps = list(map(int, file_in.read().split()))

values = []
for n in range(1, K + 1):
	for c in combinations_with_replacement(stamps, n):
		o = 1
		for v in c:
			o += v
		values.append(o)

def findLongestConseqSubseq(arr, n): 
	s = set() 
	ans=0
	for ele in arr: 
		s.add(ele) 
	for i in range(n): 
		if (arr[i]-1) not in s: 
			j=arr[i] 
			while(j in s): 
				j+=1
			ans=max(ans, j-arr[i]) 
	return ans 

file_out.write(str(findLongestConseqSubseq(values, len(values))) + "\n")

