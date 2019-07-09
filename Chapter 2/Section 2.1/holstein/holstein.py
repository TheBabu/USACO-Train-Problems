#!/usr/bin/python

"""
ID: ten.to.1
TASK: holstein
LANG: PYTHON3
"""

from itertools import combinations

file_in  = open("holstein.in", "r")
file_out = open("holstein.out", "w")

V       = int(file_in.readline())
min_vit = list(map(int, file_in.readline().split()))

G     = int(file_in.readline())
feeds = []

for n in range(0, G):
	feed = list(map(int, file_in.readline().split()))
	feeds.append(feed)

def check(test):
	found = True
	
	for n in range(0, V):
		if(test[n] < min_vit[n]):
			found = False
			break
	
	return found

def solve():
	for n in range(1, G + 1):
		combs = list(combinations(feeds, n))
		
		for comb in combs:
			test = [0] * V
			
			for feed in comb:
				for i in range(0, V):
					test[i] += feed[i]
			
			if(check(test)):
				return comb

feeds_ans = list(solve())

file_out.write(str(len(feeds_ans)) + " ")
for n in range(0, len(feeds_ans) - 1):
	file_out.write(str(feeds.index(feeds_ans[n]) + 1) + " ")
file_out.write(str(feeds.index(feeds_ans[len(feeds_ans) - 1]) + 1) + "\n")

