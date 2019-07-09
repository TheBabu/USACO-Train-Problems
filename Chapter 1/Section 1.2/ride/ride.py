"""
ID: ten.to.1
LANG: PYTHON3
TASK: ride
"""

#!/usr/bin/python

ridein     = open("ride.in", "r")
rideout    = open("ride.out", "w")
#Converstions for ALPHA to NUM
abc123 = {
"A" : 1,
"B" : 2,
"C" : 3,
"D" : 4,
"E" : 5,
"F" : 6,
"G" : 7,
"H" : 8,
"I" : 9,
"J" : 10,
"K" : 11,
"L" : 12,
"M" : 13,
"N" : 14,
"O" : 15,
"P" : 16,
"Q" : 17,
"R" : 18,
"S" : 19,
"T" : 20,
"U" : 21,
"V" : 22,
"W" : 23,
"X" : 24,
"Y" : 25,
"Z" : 26,
}

def FiletoGroupNames(filein):
	groupnames = filein.read().split("\n")
	#groupnames.pop(-1)
	groupnames.pop()
	splitnames = []
	for n in groupnames:
		splitnames.append(list(n))
	
	return splitnames 

def ALPHAtoNUM(groupnames):
	numnames = []
	tempdimen = []
	
	for n in groupnames:
		for i in n:
			tempdimen.append(abc123[i])
		
		numnames.append(tempdimen)
		tempdimen = []
	
	return numnames

def ModCheck(numnames):
	values = []
	val = 1
	
	for i in numnames:
		for n in i:
			val = val * n
		
		values.append(val % 47)
		val = 1
	
	return values[0] == values[1]

def ChecktoFile(check, fileout):
	if(check == True):
		fileout.write("GO\n")
	else:
		fileout.write("STAY\n")

splitnames = FiletoGroupNames(ridein)
numnames   = ALPHAtoNUM(splitnames)
ChecktoFile(ModCheck(numnames), rideout)

