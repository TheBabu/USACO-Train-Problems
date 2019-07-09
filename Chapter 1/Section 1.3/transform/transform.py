"""
ID: ten.to.1
LANG: PYTHON3
TASK: transform
"""

#!/usr/bin/python
import copy

filein  = open("transform.in", "r");
fileout = open("transform.out", "w")

square_length = int(filein.readline())
pattern_a     = []
pattern_b     = []

for n in range(0, square_length):
	pattern_a.append(list(filein.readline()[:-1]))

for n in range(0, square_length):
	pattern_b.append(list(filein.readline()[:-1]))

def rot_90(dimen, x, y):
	for (n, m) in zip(range(0, dimen), reversed(range(0, dimen))):
		for (i, j) in zip(range(0, dimen), (range(0, dimen))):
			
			if(not (x[n][i] == y[j][m])):
				return False
	
	return True;

def rot_180(dimen, x, y):
	for (n, m) in zip(range(0, dimen), reversed(range(0, dimen))):
		for (i, j) in zip(range(0, dimen), reversed(range(0, dimen))):
			
			if(not (x[n][i] == y[m][j])):
				return False
	
	return True;

def rot_270(dimen, x, y):
	for (n, m) in zip(range(0, dimen), (range(0, dimen))):
		for (i, j) in zip(range(0, dimen), reversed(range(0, dimen))):
			
			if(not (x[n][i] == y[j][m])):
				return False
	
	return True;

def reflect(dimen, x, y):
	for (n, m) in zip(range(0, dimen), (range(0, dimen))):
		for (i, j) in zip(range(0, dimen), reversed(range(0, dimen))):
			
			if(not (x[n][i] == y[m][j])):
				return False
	
	return True;

def combo(dimen, x, y):
	reflected_x = copy.deepcopy(x)
	
	for (n, m) in zip(range(0, dimen), (range(0, dimen))):
		for (i, j) in zip(range(0, dimen), reversed(range(0, dimen))):
			
			reflected_x[n][i] = x[m][j]
	
	if(rot_90(dimen, reflected_x, y)):
		return True
	if(rot_180(dimen, reflected_x, y)):
		return True
	if(rot_270(dimen, reflected_x, y)):
		return True
	
	return False

def no_change(dimen, x, y):
	for (n, m) in zip(range(0, dimen), range(0, dimen)):
		for (i, j) in zip(range(0, dimen), range(0, dimen)):
			
			if(not (x[n][i] == y[m][j])):
				return False
	
	return True;

reflect(square_length, pattern_a, pattern_b)

if(rot_90(square_length, pattern_a, pattern_b)):
	fileout.write("1\n")
elif(rot_180(square_length, pattern_a, pattern_b)):
	fileout.write("2\n")
elif(rot_270(square_length, pattern_a, pattern_b)):
	fileout.write("3\n")
elif(reflect(square_length, pattern_a, pattern_b)):
	fileout.write("4\n")
elif(combo(square_length, pattern_a, pattern_b)):
	fileout.write("5\n")
elif(no_change(square_length, pattern_a, pattern_b)):
	fileout.write("6\n")
else:
	fileout.write("7\n")

