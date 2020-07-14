#!/usr/bin/python

file_in  = open("spin.in", "r")
file_out = open("spin.out", "w")

speeds = []
wheels = []

for wheel in file_in.read().split("\n")[:-1]:
	info = list(map(int, wheel.split(" ")))
	speeds.append(info[0])
	
	wedges = []
	for n in range(0, info[1] + 1, 2):
		wedge = [info[n + 2], info[n + 3]]
		wedges.append(wedge)
	wheels.append(wedges)

def gen_range(a, b):
	if(a < b):
		return list(range(a, b + 1))
	if(b < a):
		return list(range(a, 360)) + list(range(0, b + 1))

for t in range(0, 15):
	for n in range(0, 360):
		can_pass_wheels = True
		
		for wheel in wheels:
			can_pass_wheel = True
			
			for wedges in wheel:
				can_pass_wedges = False
				
				if(n in gen_range(wedge[0], wedge[1])):
					can_pass_wedges = True
				
				if(not can_pass_wedges):
					can_pass_wheel = True
			
			if(not can_pass_wheel):
				can_pass_wheels = False
				break
		
		if(can_pass_wheels):
			print("YAY", t)
			break
	
	#Advance Wheels
	for n in range(0, len(wheels)):
		for j in range(0, len(wheels[n])):
			for k in range(0, len(wheels[n][j])):
				wheels[n][j][k] = (wheels[n][j][k] + speeds[n]) % 360

