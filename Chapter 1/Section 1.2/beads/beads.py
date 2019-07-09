"""
ID: ten.to.1
LANG: PYTHON3
TASK: beads
"""

#!/usr/bin/python

#Files
beadsin  = open("beads.in", "r")
beadsout = open("beads.out", "w")
#Bead Input
numofbeads = int(beadsin.readline())
beads      = list(beadsin.readline())
#Delete Newline
beads.pop(-1)

def checknumofbeads(beads, beadpos, leftchar, rightchar):
	numofbeads = 0
	
	#Left Check
	leftshift = -1
	while(beads[(beadpos + leftshift) % len(beads)] in (leftchar, 'w') and numofbeads < len(beads)):
		numofbeads += 1
		leftshift -= 1
	
	#Right Check
	rightshift = 0
	while(beads[(beadpos + rightshift) % len(beads)] in (rightchar, 'w') and numofbeads < len(beads)):
		numofbeads += 1
		rightshift += 1
	return numofbeads

#Brute Force
maxbeads = 0
for i in range(0, numofbeads):
	#Case 1: R | R
	case1 = checknumofbeads(beads, i, 'r', 'r')
	if(case1 >= maxbeads):
		maxbeads = case1
	
	#Case 2: B | B
	case2 = checknumofbeads(beads, i, 'b', 'b')
	if(case2 >= maxbeads):
		maxbeads = case2
	
	#Case 3: R | B
	case3 = checknumofbeads(beads, i, 'r', 'b')
	if(case3 >= maxbeads):
		maxbeads = case3
	
	#Case 4: B | R
	case4 = checknumofbeads(beads, i, 'b', 'r')
	if(case4 >= maxbeads):
		maxbeads = case4

#Input to File
output = str(maxbeads) + "\n"
beadsout.write(output)

