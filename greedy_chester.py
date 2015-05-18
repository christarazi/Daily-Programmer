'''
http://www.reddit.com/r/dailyprogrammer/comments/3629st/20150515_challenge_214_hard_chester_the_greedy/
'''

import math
import sys
import kdtree
import timeit

def distance(first, second):
	return (math.sqrt((first[0]-second[0])**2 + (first[1]-second[1])**2), second)

def run_kd_tree():
	t = kdtree.create(dimensions=2)
	coordinates = []
	currentCoord = (0.5, 0.5)
	totalDistance = 0.0

	t.add(currentCoord)

	fIn = open(sys.argv[1])
	N = int(fIn.readline())

	for line in fIn.readlines():
		coordInput = line.split(" ")
		x = float(coordInput[0])
		y = float(coordInput[1])
		t.add((x, y))

	start = timeit.default_timer()
	# Using k-d tree
	for i in range(N+1):
		new = t.search_knn(currentCoord, 2)[-1]		# returns closest point to currentCoord
		t = t.remove(currentCoord)					# mark as visited by removing
		totalDistance += float(new[1])
		currentCoord = eval(str(new[0]))			# convert into tuple

	end = timeit.default_timer()
	fIn.close()

	print("\nTotal distance traveled:", end='')
	print(repr(totalDistance).rjust(25))
	print("Total time taken:", end='')
	print(repr(end-start).rjust(32))

def run_brute_force():
	coordinates = []
	currentCoord = (0.5, 0.5)
	totalDistance = 0.0
	sortedDistances = []

	fIn = open(sys.argv[1])
	N = int(fIn.readline())

	for line in fIn.readlines():
		coordInput = line.split(" ")
		x = float(coordInput[0])
		y = float(coordInput[1])
		coordinates.append((x, y))

	start = timeit.default_timer()
	while len(coordinates) != 0:
		# Sort coordinates by their distance from currentCoord
		for i in coordinates:
			sortedDistances.append(distance(currentCoord, i))

		sortedDistances.sort()

		currentCoord = sortedDistances[0][1]		# gets next coordinate
		totalDistance += sortedDistances.pop(0)[0]	# adds minimum distance in list to total
		sortedDistances.clear()						# list must be cleared for new coordinate
		coordinates.remove(currentCoord)			# acts as a loop counter

	end = timeit.default_timer()
	fIn.close()

	print("\nTotal distance traveled:", end='')
	print(repr(totalDistance).rjust(25))
	print("Total time taken:", end='')
	print(repr(end-start).rjust(32))

def main():
	
	if len(sys.argv) != 2:
		print("usage: " + sys.argv[0] + " <file>")
		exit(1)

	print("\n\n1) Run using brute force")
	print("2) Run using k-d tree")

	method = input("> ")
	if int(method) == 1:
		run_brute_force()
	elif int(method) == 2:
		run_kd_tree()
	else:
		print("Error. Pick from the above list.")
		exit(2)

	'''
	For user input

	for i in range(int(input())):
		coordInput = input("Coordinates " + str(i+1) + ": ").split(" ")
		x = float(coordInput[0])
		y = float(coordInput[1])
		coordinates.append((x, y))

	print(coordinates)
	'''

if __name__ == '__main__':
	main()