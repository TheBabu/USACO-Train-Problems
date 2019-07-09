"""
ID: ten.to.1
TASK: preface
LANG: PYTHON3
"""

#!/usr/bin/python

file_in  = open("preface.in", "r")
file_out = open("preface.out", "w")

N = int(file_in.read())

symbols = [0] * 7

def I(n):
	if(n % 10 == 1 or n % 10 == 6 or n % 10 == 4 or n % 10 == 9):
		symbols[0] += 1
	elif(n % 10 == 2 or n % 10 == 7):
		symbols[0] += 2
	elif(n % 10 == 3 or n % 10 == 8):
		symbols[0] += 3

def V(n):
	if(n % 10 >= 4 and n % 10 <= 8):
		symbols[1] += 1

def X(n):
	last = int(str(n)[-2:])
	if(last >= 1 and last <= 8):
		#print(n, 0)
		symbols[2] += 0
	elif((last >= 9 and last <= 18) or (last >= 40 and last <= 48) or (last >= 59 and last <= 68) or (last >= 90 and last <= 98)):
		#print(n, 1)
		symbols[2] += 1
	elif((last >= 19 and last <= 28) or (last == 49) or (last >= 69 and last <= 78) or (last == 99)):
		#print(n, 2)
		symbols[2] += 2
	elif((last >= 29 and last <= 38) or (last >= 79 and last <= 88)):
		#print(n, 3)
		symbols[2] += 3
	elif(last == 39 or last == 89):
		#print(n, 4)
		symbols[2] += 4

def L(n):
	last = int(str(n)[-2:])
	if(last >= 40 and last <= 89):
		symbols[3] += 1

def C(n):
	last = int(str(n)[-3:])
	if((last >= 0 and last <= 89) or (last >= 500 and last <= 589)):
		#print(n, 0)
		symbols[4] += 0
	elif((last >= 90 and last <= 189) or (last >= 400 and last <= 489) or (last >= 590 and last <= 689) or (last >= 900 and last <= 989)):
		#print(n, 1)
		symbols[4] += 1
	elif((last >= 190 and last <= 289) or (last >= 490 and last <= 499) or (last >= 690 and last <= 789) or (last >= 990 and last <= 999)):
		#print(n, 2)
		symbols[4] += 2
	elif((last >= 290 and last <= 389) or (last >= 790 and last <= 889)):
		#print(n, 3)
		symbols[4] += 3
	elif((last >= 390 and last <= 399) or (last >= 890 and last <= 899)):
		#print(n, 4)
		symbols[4] += 4

def D(n):
	last = int(str(n)[-3:])
	if(last >= 400 and last <= 899):
		symbols[5] += 1

def M(n):
	if(n >= 900 and n <= 1899):
		symbols[6] += 1
	elif(n >= 1900 and n <= 2899):
		symbols[6] += 2
	elif(n >= 2900 and n <= 3500):
		symbols[6] += 3

for n in range(1, N + 1):
	I(n)
	V(n)
	X(n)
	L(n)
	C(n)
	D(n)
	M(n)

for n in range(0, len(symbols)):
	if(symbols[n] != 0):
		if(n == 0):
			file_out.write("I " + str(symbols[n]) + "\n")
		if(n == 1):
			file_out.write("V " + str(symbols[n]) + "\n")
		if(n == 2):
			file_out.write("X " + str(symbols[n]) + "\n")
		if(n == 3):
			file_out.write("L " + str(symbols[n]) + "\n")
		if(n == 4):
			file_out.write("C " + str(symbols[n]) + "\n")
		if(n == 5):
			file_out.write("D " + str(symbols[n]) + "\n")
		if(n == 6):
			file_out.write("M " + str(symbols[n]) + "\n")

