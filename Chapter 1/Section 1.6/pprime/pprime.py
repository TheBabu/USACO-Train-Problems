"""
ID: ten.to.1
LANG: PYTHON3
TASK: pprime
"""
from math import sqrt; from itertools import count, islice

def isPrime(n):
	return n > 1 and all(n%i for i in islice(count(2), int(sqrt(n)-1)))

#NAIVE SOLUTION
#Better solutions would've been just to iterate x amount of digits then just reverse it...

filein  = open("pprime.in", "r")
fileout = open("pprime.out", "w")
a, b    = map(int, filein.read().split())

start = len(str(a))
end   = len(str(b))
nums  = []

def check(n):
	if(n >= a and n <= b and isPrime(n)):
			nums.append(n)

def palin1():
	for n in range(0, 10):
		check(n)

def palin2():
	for n in range(0, 10):
		check(int(str(n) + str(n)))

def palin3():
	for n in range(0, 10):
		for j in range(1, 10):
			check(int(str(j) + str(n) + str(j)))

def palin4():
	for n in range(0, 10):
		for j in range(1, 10):
			check(int(str(j) + str(n) + str(n) + str(j)))

def palin5():
	for n in range(0, 10):
		for j in range(0, 10):
			for k in range(1, 10):
				check(int(str(k) + str(j) + str(n) + str(j) + str(k)))

def palin6():
	for n in range(0, 10):
		for j in range(0, 10):
			for k in range(1, 10):
				check(int(str(k) + str(j) + str(n) + str(n) + str(j) + str(k)))

def palin7():
	for n in range(0, 10):
		for j in range(0, 10):
			for k in range(0, 10):
				for l in range(1, 10):
					check(int(str(l) + str(k) + str(j) + str(n) + str(j) + str(k) + str(l)))

def palin8():
	for n in range(0, 10):
		for j in range(0, 10):
			for k in range(0, 10):
				for l in range(1, 10):
					check(int(str(l) + str(k) + str(j) + str(n) + str(n) + str(j) + str(k) + str(l)))

for n in range(start, end + 1):
	if(n == 1):
		palin1()
	elif(n == 2):
		palin2()
	elif(n == 3):
		palin3()
	elif(n == 4):
		palin4()
	elif(n == 5):
		palin5()
	elif(n == 6):
		palin6()
	elif(n == 7):
		palin7()
	elif(n == 8):
		palin8()

nums.sort()
for n in nums:
	fileout.write(str(n) + "\n")

