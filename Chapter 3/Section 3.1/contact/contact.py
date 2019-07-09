"""
ID: ten.to.1
TASK: contact
LANG: PYTHON3
"""

#!/usr/bin/python

import operator

file_in  = open("contact.in", "r")
file_out = open("contact.out", "w")

A, B, N = map(int, file_in.readline().split())
wave    = file_in.read().replace('\n', '')

freq = { }

for k in range(A, B + 1):
	for n in range(0, len(wave) - k + 1):
		if(wave[n : n + k] not in freq.keys()):
			freq[wave[n : n + k]] = 1
		else:
			freq[wave[n : n + k]] += 1

freq = sorted(freq.items(), key=operator.itemgetter(1), reverse=True)

new_freq = { }

for n in freq:
	if(n[1] not in new_freq.keys()):
		new_freq[n[1]] = []
		new_freq[n[1]].append(n[0])
	else:
		new_freq[n[1]].append(n[0])

values = [ [k,v] for k, v in new_freq.items() ]

N = min(len(values), N)

for n in range(0, N):
	v = values[n]
	file_out.write(str(v[0]) + "\n")
	
	v[1].sort(key=lambda x: int(x, base=2))
	v[1].sort(key=len)
	
	for k in range(0, len(v[1])):
		if(k == len(v[1]) - 1):
			file_out.write(v[1][k] + "\n")
		elif((k + 1) % 6 == 0):
			file_out.write(v[1][k] + "\n")
		else:
			file_out.write(v[1][k] + " ")

