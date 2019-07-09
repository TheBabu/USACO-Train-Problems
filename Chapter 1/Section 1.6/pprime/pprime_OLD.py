"""
ID: ten.to.1
LANG: PYTHON3
TASK: pprime
"""
from math import sqrt; from itertools import count, islice

def isPrime(n):
	return n > 1 and all(n%i for i in islice(count(2), int(sqrt(n)-1)))

def combine(arr):
	num = 0
	for n in range(0, len(arr)):
		num += (10 ** (len(arr) - n - 1)) * arr[n]
	return num

f_in  = open("pprime.in", "r")
f_out = open("pprime.out", "w")
a, b  = map(int, f_in.read().split())

num = list(map(int, [x for x in str(a)]))
while(True):
	if(len(num) == 1):
		print(num)
	elif(len(num) % 2 == 0):
		print(num)
	else:
		print(num)
	break

