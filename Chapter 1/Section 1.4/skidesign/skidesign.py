#!/usr/bin/python

"""
ID: ten.to.1
TASK: skidesign
LANG: PYTHON3
"""

filein  = open("skidesign.in", "r")
fileout = open("skidesign.out", "w")

filein.readline()
hill_heigths = sorted(list(map(int, filein.read().split())))
changes      = []

print(hill_heigths)

while(True):
	max_height    = max(hill_heigths)
	min_height    = min(hill_heigths)
	displacement  = max_height - min_height
	change_needed = int((displacement - 17) / 2)
	
	if(change_needed == 0):
		break
	
	#print(min(hill_heigths), max(hill_heigths))
	#print("\t", displacement)
	#print(hill_heigths)
	
	changes.append(change_needed)
	changes.append(change_needed)
	
	hill_heigths[hill_heigths.index(max_height)] = hill_heigths[hill_heigths.index(max_height)] - change_needed
	hill_heigths[hill_heigths.index(min_height)] = hill_heigths[hill_heigths.index(min_height)] + change_needed

print(changes)

cost = 0
for n in changes:
	cost += n**2

fileout.write(str(cost) + '\n')

