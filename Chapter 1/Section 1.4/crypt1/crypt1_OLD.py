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

#print(numbers)

num_of_solutions = 0

for a in numbers:
	for b in numbers:
		for c in numbers:
			for d in numbers:
				for e in numbers:
					p1  = [e * a, e * b, e * c]
					p2  = [d * a, d * b, d * c]
					sum = int(''.join([str(e * a), str(e * b), str(e * c)])) + int(''.join([str(d * a), str(d * b), str(d * c)])) * 10
					
					num_of_solutions += 1
					
					for x, y, z in zip(p1, p2, map(int, str(sum))):
						if(not(x in numbers and y in numbers and z in numbers)):
							print("\n", [a,b,c], [d,e], "\n", p1, "\n", p2, "\n", sum, "\n")
							num_of_solutions -= 1
							break

print(num_of_solutions)

fileout.write(str(num_of_solutions) + "\n")

