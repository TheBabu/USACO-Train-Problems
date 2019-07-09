#!/usr/bin/python

"""
ID: ten.to.1
TASK: holstein
LANG: PYTHON3
"""

from itertools import combinations
import sys

file_in  = open("holstein.in", "r")
file_out = open("holstein.out", "w")

V       = int(file_in.readline())
min_vit = list(map(int, file_in.readline().split()))

G     = int(file_in.readline())
feeds = []

for n in range(0, G):
	feed = list(map(int, file_in.readline().split()))
	feeds.append(feed)

acc = []
for n in range(0, V):
	acc.append(n)


def solve():
	for n in range(1, V + 1):
		curr = list(combinations(acc, n))
		
		for j in curr:
			test = [0] * V
			for k in j:
				for l in range(0, V):
					test[l] += (feeds[k][l])
			
			found = True
			for p in range(0, V):
				if(test[p] <= min_vit[p]):
					found = False
			
			if(found):
				return j

ans = list(solve())
file_out.write(str(len(ans)) + " ")
for n in range(0, len(ans)):
	file_out.write(str(ans[n] + 1) + " ")


