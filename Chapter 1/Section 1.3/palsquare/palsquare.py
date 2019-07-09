"""
ID: ten.to.1
LANG: PYTHON3
TASK: palsquare
"""

#!/usr/bin/python

#Files
palsquarein  = open("palsquare.in", "r")
palsquareout = open("palsquare.out", "w")

#Variables
base          = int(palsquarein.read())
maxnum        = 301;

def base10tobaseX(base10num, baseX):
	valtosym = {
	0  : "0",
	1  : "1",
	2  : "2",
	3  : "3",
	4  : "4",
	5  : "5",
	6  : "6",
	7  : "7",
	8  : "8",
	9  : "9",
	10 : "A",
	11 : "B",
	12 : "C",
	13 : "D",
	14 : "E",
	15 : "F",
	16 : "G",
	17 : "H",
	18 : "I",
	19 : "J",
	20 : "K"
	}
	baseXnum = []
	
	while (base10num > 0):
		(base10num, val) = divmod(base10num, baseX)
		baseXnum.append(valtosym[val])
	
	return ''.join(list(reversed(baseXnum)))

def checkpalindrome(numlist):
	if(numlist == numlist[::-1]):
		return True
	else:
		return False

#Brute Force
for n in range(1, maxnum):
	base10num   = base10tobaseX(n, base)
	basenumsqrd = base10tobaseX(n ** 2, base)
	output      = base10num + " " + basenumsqrd + "\n"
	
	if(basenumsqrd == basenumsqrd[::-1]):
		palsquareout.write(output)

