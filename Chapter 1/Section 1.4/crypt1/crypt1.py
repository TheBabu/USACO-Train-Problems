#!/usr/bin/python

"""
ID: ten.to.1
TASK: crypt1
LANG: PYTHON3
"""

filein  = open("crypt1.in", "r")
fileout = open("crypt1.out", "w")

filein.readline()
numbers = list(map(int, filein.readline().split()))

num_of_solutions = 0

def good_num(numbers, num):
	for n in str(num):
		if not(n in str(numbers)):
			return False
	
	return True

for a in numbers:
	for b in numbers:
		for c in numbers:
			for d in numbers:
				for e in numbers:
					p1  = e * int(str(a) + str(b) + str(c))
					p2  = 10 * d * int(str(a) + str(b) + str(c))
					sum = p1 + p2
					p2  = p2 // 10
					
					if(good_num(numbers, p1) and good_num(numbers, p2) and good_num(numbers, sum) and len(list(str(p1))) <= 3 and len(list(str(p2))) <= 3):
						#print(a, b, c, d, e)
						#print(p1, p2, sum)
						#print()
						num_of_solutions += 1

#print(num_of_solutions)

fileout.write(str(num_of_solutions) + "\n")

