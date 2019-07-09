"""
ID: ten.to.1
TASK: frac1
LANG: PYTHON3
"""

from fractions import Fraction

filein  = open("frac1.in", "r")
fileout = open("frac1.out", "w")

N = int(filein.read())
fracs = []

for n in range(1, N + 1):
	for j in range(0, n + 1):
		fracs.append(Fraction(j, n))

fracs = list(set(fracs))

fracs.sort()

for k in fracs:
	fileout.write(str(k.numerator) + "/" + str(k.denominator) + "\n")

