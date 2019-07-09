"""
ID: ten.to.1
TASK: fracdec
LANG: PYTHON3
"""

#!/usr/bin/python

import re
import sys

file_in  = open("fracdec.in", "r")
file_out = open("fracdec.out", "w")

N, D = map(int, file_in.read().split())

ans = ""

quotient = N // D
rest     = N - (quotient * D)

decimal_str = str(quotient) + "."
for n in range(1, 100000):
	rest   = rest * 10
	append = rest // D
	
	rest -= append * D
	 
	decimal_str += str(append)
	
	if(rest == 0):
		ans = decimal_str
		for n in range(0, len(ans)):
			file_out.write(ans[n])
			if((n + 1) % 76 == 0):
				file_out.write("\n")
		file_out.write("\n")
		
		sys.exit(0)

r              = re.compile(r"(.+?)\1+")
repeating_list = r.findall(decimal_str)
index          = 0

if(len(repeating_list) == 0):
	ans = decimal_str
else:
	if(max(repeating_list, key = len)[-1] == repeating_list[0]):
		count = 0
		for n in max(repeating_list, key = len)[::-1]:
			if(n == repeating_list[0]):
				count += 1
			else:
				break
		
		ans += str(quotient) + ".(" + (str(0) * count) + max(repeating_list)[:len(max(repeating_list, key = len)) - count] + ")"
	
	else:
		index = decimal_str.index(max(repeating_list, key = len))
		ans = decimal_str[0:index] + "(" + max(repeating_list, key = len) + ")"

for n in range(0, len(ans)):
	file_out.write(ans[n])
	if((n + 1) % 76 == 0):
		file_out.write("\n")
file_out.write("\n")

