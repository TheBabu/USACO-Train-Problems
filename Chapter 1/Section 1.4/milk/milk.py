#!/usr/bin/python

"""
ID: ten.to.1
TASK: milk
LANG: PYTHON3
"""

filein  = open("milk.in", "r")
fileout = open("milk.out", "w")

info       = list(map(int, filein.readline().split()));
cost_units = []

for n in range(0, info[1]):
	inp = list(map(int, filein.readline().split()))
	
	cost_units.append((inp[0], inp[1]))

cost_units = sorted(cost_units)

print(cost_units)

total_cost  = 0
total_units = 0

for n in cost_units:
	if(info[0] - (total_units + n[1]) > 0):
		total_cost += n[0] * n[1]
		total_units += n[1]
	else:
		total_cost += n[0] * (info[0] - total_units)
		break

print(total_cost)
fileout.write(str(total_cost) + '\n')

