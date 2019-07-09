"""
ID: ten.to.1
LANG: PYTHON3
TASK: dualpal
"""

#!/usr/bin/python

filein  = open("dualpal.in", "r")
fileout = open("dualpal.out", "w")

num_list            = list(map(int, filein.read().split()))
n_lines             = num_list[0]
current_base_10_num = num_list[1] + 1

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

def check_pal(num):
	num_list = list(map(int, list(str(num))))
	
	if(num_list[0] == 0):
		return False
	
	if(num_list[::] == num_list[::-1]):
		return True
	else:
		return False

#Go through each base
solutions = []

while True:
	num_of_pals = 0
	
	for current_base in range(2, 11):
		if(check_pal(base10tobaseX(current_base_10_num, current_base))):
			num_of_pals += 1
	
	if(num_of_pals >= 2):
		solutions.append(current_base_10_num)
	
	current_base_10_num += 1
	
	if(len(solutions) >= n_lines):
		break

for n in solutions:
	fileout.write(str(n) + "\n")

