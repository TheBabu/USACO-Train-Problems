"""
ID: ten.to.1
TASK: sort3
LANG: PYTHON3
"""

filein  = open("sort3.in", "r")
fileout = open("sort3.out", "w")

N    = int(filein.readline())
nums = []
for n in range(0, N):
	nums.append(int(filein.readline()))
ones   = nums.count(1)
twos   = nums.count(2)
threes = nums.count(3)

print(end="   ")
for n in range(0, ones):
	print("1  ", end="")
for n in range(0, twos):
	print("2  ", end="")
for n in range(0, threes):
	print("3  ", end="")
print()

swaps = 0

def debug(n, i):
	str = "   "
	for n in range(0, n):
		str += "   "
	str += "#"
	for n in range(n, i):
		str+= "   "
	str = str[:-4]
	str += "^"
	print(str)

print(swaps, nums)
#Ones
for n in range(0, ones):
	if(nums[n] == 2):
		debug(n, nums.index(1, ones))
		nums[n], nums[nums.index(1, ones)] = nums[nums.index(1, ones)], nums[n]
		swaps += 1
		print(swaps, nums)
	elif(nums[n] == 3):
		debug(n, len(nums) - 1 - nums[::-1].index(1))
		nums[n], nums[len(nums) - 1 - nums[::-1].index(1)] = nums[len(nums) - 1 - nums[::-1].index(1)], nums[n]
		swaps += 1
		print(swaps, nums)

#Twos
for n in range(ones, ones + twos):
	if(nums[n] != 2):
		debug(n, nums.index(2, ones + twos))
		nums[n], nums[nums.index(2, ones + twos)] = nums[nums.index(2, ones + twos)], nums[n]
		swaps += 1
		print(swaps, nums)

fileout.write(str(swaps) + "\n")

