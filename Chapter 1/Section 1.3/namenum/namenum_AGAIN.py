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
#Lists
namnum       = list(map(int, namnumstring))
allnames     = dicttxt.read().split()
#Lengths
namenumlen   = len(namnum)
allnameslen  = len(allnames)
#Binary values on if a name is valid
validnames   = []
#Keymaps
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
for i in range(0, allnameslen):
	if(len(allnames[i]) == namenumlen):
		validnames.append(True)
	else:
		validnames.append(False)

#Check each Word
for i in range(0, allnameslen):
	if(validnames[i] == True):
		for n in range(0, namenumlen):
			if(namnum[n] != keymaps[allnames[i][n]]):
				validnames[i] = False
				break

#Write to File
nosol = True
for i in range(0, allnameslen):
	if(validnames[i] == True):
		nosol  = False
		output = allnames[i] + "\n"
		namenumout.write(output)
if(nosol):
	namenumout.write("NONE\n")

