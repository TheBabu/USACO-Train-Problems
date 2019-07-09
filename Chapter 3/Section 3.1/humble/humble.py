"""
ID: ten.to.1
TASK: humble
LANG: PYTHON3
"""

#!/usr/bin/python

from itertools import combinations_with_replacement
import bisect

file_in  = open("humble.in", "r")
file_out = open("humble.out", "w")

K, N = map(int, file_in.readline().split())
P    = list(map(int, file_in.read().split()))
S    = P.copy()



