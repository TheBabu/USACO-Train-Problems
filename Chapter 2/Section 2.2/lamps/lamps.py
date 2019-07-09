"""
ID: ten.to.1
TASK: lamps
LANG: PYTHON3
"""

#!/usr/bin/python

from itertools import combinations
import itertools

file_in  = open("lamps.in", "r")
file_out = open("lamps.out", "w")

N            = int(file_in.readline())
C            = int(file_in.readline())
on           = list(map(int, file_in.readline().split()))
off          = list(map(int, file_in.readline().split()))
known_config = [-1] * (N + 1)

for n in range(0, len(on) - 1):
	known_config[on[n]] = 1

for n in range(0, len(off) - 1):
	known_config[off[n]] = 0

def b1(states):
	for n in range(1, N + 1):
		if(states[n] == 1):
			states[n] = 0
		else:
			states[n] = 1

def b2(states):
	for n in range(1, N + 1, 2):
		if(states[n] == 1):
			states[n] = 0
		else:
			states[n] = 1

def b3(states):
	for n in range(2, N + 1, 2):
		if(states[n] == 1):
			states[n] = 0
		else:
			states[n] = 1

def b4(states):
	for n in range(1, N + 1, 3):
		if(states[n] == 1):
			states[n] = 0
		else:
			states[n] = 1

def compare(k, d):
	for n in range(1, N + 1):
		if(k[n] == 1 and k[n] != d[n]):
			return False
		elif(k[n] == 0 and k[n] != d[n]):
			return False
	
	return True

good = []
buttons = [b1, b2, b3, b4]

if(C <= 3):
	for n in range(0, C + 1):
		combs = list(combinations(buttons, n))
		for c in combs:
			states = [1] * (N + 1)
			for d in c:
				d(states)
			if(compare(known_config, states)):
				good.append(states)
else:
	for n in range(0, 4):
		combs = list(combinations(buttons, n))
		for c in combs:
			states = [1] * (N + 1)
			for d in c:
				d(states)
			if(compare(known_config, states)):
				good.append(states)

if(len(good) == 0):
	file_out.write("IMPOSSIBLE\n")
else:
	good.sort()
	good = list(k for k,_ in itertools.groupby(good))
	for g in good:
		for n in range(1, N + 1):
			file_out.write(str(g[n]))
		file_out.write("\n")

