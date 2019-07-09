"""
ID: ten.to.1
LANG: PYTHON3
TASK: milk2
"""

#!/usr/bin/python

filein  = open("milk2.in", "r");
fileout = open("milk2.out", "w");

print(filein.readline());
time_list = list(map(int, filein.read().split()))

class time:
	start_times_raw        = time_list[::2]
	end_times_raw          = time_list[1::2]
	start_times, end_times = list(zip(*sorted(list(zip(start_times_raw, end_times_raw)))))
	range_times            = list(map(lambda st, et : range(st, et + 1), start_times, end_times))
	
	idle_start_times = start_times[1:]
	idle_end_times   = end_times[:-1]
	idle_range_times = list(map(lambda st, et : range(st + 1, et), start_times, end_times))
	
	def in_ranges(current_time, ranges):
		for current_range in ranges:
			if(current_time in current_range):
				return True
		
		return False

print("time_list        = ", time_list)
#print("time.start_times = ", time.start_times)
#print("time.end_times   = ", time.end_times)
#print("time.range_times = ", time.range_times)
#print("time.idle_range_times = ", time.idle_range_times)

#Longest Work Time
longest_work_time = time.end_times[0] - time.start_times[0]

current_start_time = time.start_times[0]
current_end_time   = time.end_times[0]

for n in range(0, len(time.end_times)):
	for current_range in time.range_times:
		if(time.end_times[n] in current_range):
			current_end_time = time.end_times[n]
			if(current_end_time - current_start_time > longest_work_time):
				longest_work_time = current_end_time - current_start_time
		else:
			current_start_time = time.start_times[n]

#Longest Idle Time
longest_idle_time = 0

for (start, end) in zip(time.idle_start_times, time.idle_end_times):
	if(not time.in_ranges(start, time.idle_range_times) and not time.in_ranges(start, time.idle_range_times)):
		if(start - end > longest_idle_time):
			longest_idle_time = start - end

#Output
fileout.write(str(longest_work_time) + " " + str(longest_idle_time) + "\n")

