#!/usr/bin/python
"""
ID: ten.to.1
LANG: PYTHON3
PROB: spin
"""

import itertools

def create_set_range(a, b):
	if(a + b < 360):
		return set(range(a, a + b + 1))
	else:
		return set(range(a, 360)).union(set(range(0, abs(360 - (a + b)))))

file_in  = open("spin.in", "r")
file_out = open("spin.out", "w")

speeds = []
wheels = []

for wheel_str in file_in.read().split("\n")[:-1]:
	wheel = list(map(int, wheel_str.split(" ")))
	
	speeds.append(wheel[0])
	
	wedges = []
	for n in range(0, wheel[1] * 2, 2):
		wedge = [wheel[n + 2], wheel[n + 3]]
		wedges.append(wedge)
	wheels.append(wedges)



hit = False
for time in range(0, 500):
	wedges_sets = []
	
	for w in range(0, len(wheels)):
		temp = []
		
		for wedge in wheels[w]:
			temp.append(create_set_range((wedge[0] + speeds[w] * time) % 360, wedge[1]))
		
		wedges_sets.append(temp)
	
	combinations = itertools.product(*wedges_sets)
	
	for c in combinations:
		if(set.intersection(*c)):
			hit = True
			break
	
	if(hit):
		break

if(hit):
	file_out.write(str(time) + '\n')
else:
	file_out.write("none\n");

