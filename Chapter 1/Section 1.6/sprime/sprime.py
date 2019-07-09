"""
ID: ten.to.1
LANG: PYTHON3
TASK: sprime
"""
from math import sqrt; from itertools import count, islice

def isPrime(n):
	return n > 1 and all(n%i for i in islice(count(2), int(sqrt(n)-1)))

def combine(arr):
	num = 0
	for n in range(0, len(arr)):
		num += (10 ** (len(arr) - n - 1)) * arr[n]
	return num

super_primes = []

def solve(N, digits):
	if(len(digits) == N):
		super_primes.append(combine(digits))
	
	for n in range(0, 10):
		digits.append(n)
		#print(digits)
		if(isPrime(combine(digits))):
			solve(N, digits)
		digits.pop()

f_in  = open("sprime.in", "r")
f_out = open("sprime.out", "w")
N     = int(f_in.read())

solve(N, [])

for n in super_primes:
	f_out.write(str(n) + "\n")
	
	#Print Super Primes
	#print(n)

