#!/usr/bin/python

"""
ID: ten.to.1
TASK: barn1
LANG: PYTHON3
"""

filein  = open("barn1.in", "r")
fileout = open("barn1.out", "w")

num_max_boards, num_total_stalls, num_occupied_stalls = list(map(int, filein.readline().split()))
occupied_stalls                                       = sorted(list(map(int, filein.read().split())))
gaps_stalls                                           = []
for n in range(1, len(occupied_stalls)):
	gaps_stalls.append(occupied_stalls[n] - occupied_stalls[n - 1])

print(occupied_stalls)
print(sorted(gaps_stalls)[:-(num_max_boards - 1)])
print(sum(sorted(gaps_stalls)[:-(num_max_boards - 1)]) + num_max_boards)

if(num_max_boards == 1):
	fileout.write(str(sum(gaps_stalls) + 1)+ '\n')
elif(num_max_boards >= len(occupied_stalls)):
	fileout.write(str(len(occupied_stalls)) + '\n')
else:
	fileout.write(str(sum(sorted(gaps_stalls)[:-(num_max_boards - 1)]) + num_max_boards) + '\n')

