"""
ID: ten.to.1
TASK: numtri
LANG: PYTHON3
"""

class TriNode:
	def __init__(self, val):
		self.value = val
		self.right = None
		self.left  = None

f_in  = open("numtri.in", "r");
f_out = open("numtri.out", "w")
R     = int(f_in.readline())

nodes = []

for i in range(0, R):
	nodes.append(list(map(TriNode, map(int, f_in.readline().split()))))

for i in range(0, R - 1):
	for j in range(0, i + 1):
		nodes[i][j].left  = nodes[i + 1][j]
		nodes[i][j].right = nodes[i + 1][j + 1]

#Print Nodes
#for n in nodes:
#	for j in n:
#		print(j.value, end=" ")
#	print()

max = 0

def solve(node, sum):
	sum += node.value;
	
	if(node.left == None):
		if(sum > max):
			max = sum
		return
	
	solve(node.left, sum)
	solve(node.right, sum)

solve(nodes[0][0], 0)

f_out.write(str(max) + "\n")

