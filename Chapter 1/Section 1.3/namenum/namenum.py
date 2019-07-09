"""
ID: ten.to.1
LANG: PYTHON3
TASK: namenum
"""

#!/usr/bin/python

#Files
namenumin    = open("namenum.in", "r")
namenumout   = open("namenum.out", "w")
dicttxt      = open("dict.txt", "r")
#Variables
namnumstring = list(namenumin.read()); namnumstring.pop(-1)
namnum       = list(map(int, namnumstring))
namenumlen   = len(namnum)
allnames     = dicttxt.read().split()
samelennames = []
invalidnames = []
keymaps      = {
"A" : 2,
"B" : 2,
"C" : 2,
"D" : 3,
"E" : 3,
"F" : 3,
"G" : 4,
"H" : 4,
"I" : 4,
"J" : 5,
"K" : 5,
"L" : 5,
"M" : 6,
"N" : 6,
"O" : 6,
"P" : 7,
"Q" : 0,
"R" : 7,
"S" : 7,
"T" : 8,
"U" : 8,
"V" : 8,
"W" : 9,
"X" : 9,
"Y" : 9,
"Z" : 0
}

#Brute Force
#Num of Digits == Length of Name
for name in allnames:
	if(len(name) == namenumlen):
		samelennames.append(name)

#Find Invalid Names
for i in range(0, len(namnum)):
	for n in range(0, len(samelennames)):
		if(namnum[i] != keymaps[samelennames[n][i]]):
				invalidnames.append(samelennames[n])

#Find Valid Names
validnames = sorted(list(set(samelennames) - set(invalidnames)))

#Write to File
if(len(validnames) == 0):
	namenumout.write("NONE\n")
else:
	for i in validnames:
		output = i + "\n"
		namenumout.write(output)

