"""
ID: ten.to.1
LANG: PYTHON3
TASK: milk2
"""

#!/usr/bin/python

filein  = open("milk2.in", "r");
fileout = open("milk2.out", "w");

filein.readline();
time_list = list(map(int, filein.read().split()))

class time:
	start_times = time_list[::2]
	end_times   = time_list[1::2]
	range_times = list(map(lambda s, e : range(s, e), start_times, end_times))
	total_range = range(min(time_list), max(time_list) + 1)
	
	def check_state(current_time, range_times):
		for current_range in range_times:
			if(current_time in current_range):
				return True
		return False

longest_work_time = 0
longest_idle_time = 0

current_work_time = 0
current_idle_time = 0

for current_time in time.total_range:
	if(time.check_state(current_time, time.range_times)):
		current_work_time += 1
		
		if(current_idle_time > longest_idle_time):
			longest_idle_time = current_idle_time
		current_idle_time = 0
	else:
		current_idle_time += 1
		
		if(current_work_time > longest_work_time):
			longest_work_time = current_work_time
		
		current_work_time = 0

output = str(longest_work_time) + " " + str(longest_idle_time) + "\n"
fileout.write(output)

