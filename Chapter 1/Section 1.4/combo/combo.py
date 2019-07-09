#!/usr/bin/python

"""
ID: ten.to.1
TASK: combo
LANG: PYTHON3
"""

filein  = open("combo.in", "r")
fileout = open("combo.out", "w")

domain     = list(range(1, int(filein.readline()) + 1))
combo_fj   = list(map(int, filein.readline().split()))
combo_mast = list(map(int, filein.readline().split()))

possible_fj_1 = []
possible_fj_2 = []
possible_fj_3 = []

possible_mast_1 = []
possible_mast_2 = []
possible_mast_3 = []

for n in [-2, -1, 0, 1, 2]:
	possible_fj_1.append(domain[(domain.index(combo_fj[0]) + n) % len(domain)])
	possible_fj_2.append(domain[(domain.index(combo_fj[1]) + n) % len(domain)])
	possible_fj_3.append(domain[(domain.index(combo_fj[2]) + n) % len(domain)])
	
	possible_mast_1.append(domain[(domain.index(combo_mast[0]) + n) % len(domain)])
	possible_mast_2.append(domain[(domain.index(combo_mast[1]) + n) % len(domain)])
	possible_mast_3.append(domain[(domain.index(combo_mast[2]) + n) % len(domain)])

#print(combo_fj)
print(possible_fj_1, possible_fj_2, possible_fj_3)
#print(combo_mast)
print(possible_mast_1, possible_mast_2, possible_mast_3)

good_num_combos = 0
for x in domain:
	for y in domain:
		for z in domain:
			if(x in possible_fj_1 and y in possible_fj_2 and z in possible_fj_3):
				good_num_combos += 1
				continue
			
			if(x in possible_mast_1 and y in possible_mast_2 and z in possible_mast_3):
				good_num_combos += 1

fileout.write(str(good_num_combos) + '\n')

