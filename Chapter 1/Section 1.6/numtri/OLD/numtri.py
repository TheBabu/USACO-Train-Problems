"""
ID: ten.to.1
TASK: numtri
LANG: PYTHON3
"""
import copy

f_in  = open("numtri.in", "r");
f_out = open("numtri.out", "w")
R     = int(f_in.readline())

nodes = []

for i in range(0, R):
	nodes.append(list(map(int, f_in.readline().split())))

maxi = 0

def solve(p, q, sum, nodes, R):
	sum += nodes[p][q]
	
	if(p == R - 1):
		if(sum > maxi):
			maxi = sum
		return
	
	solve(p + 1, q, sum, nodes, R)
	solve(p + 1, q + 1, sum, nodes, R)

solve(0, 0, 0, nodes, R)

f_out.write(str(maxi) + "\n")

