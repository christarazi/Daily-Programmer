'''
/r/dailyprogrammer Challenge #201 
'''
import random
import string

class DoublePriorityQueue():
	def __init__(self):
		self.queue = []

	def enqueue(self, s, priorA, priorB):
		self.queue.append((s, priorA, priorB))

	def dequeueA(self):
		value = sorted(self.queue, key=lambda x: x[1], reverse=True).pop(0)
		self.queue.remove(value)
		return value

	def dequeueB(self):
		value = sorted(self.queue, key=lambda x: x[2], reverse=True).pop(0)
		self.queue.remove(value)
		return value

	def dequeueFirst(self):
		return self.queue.pop(0)

	def count(self):
		return len(self.queue)

	def clear(self):
		self.queue.clear()

def main():
	dpq = DoublePriorityQueue()

	dpq.enqueue("needle", 1.99, 3)
	dpq.enqueue("syringe", .89, 7)
	dpq.enqueue("plated needle", 2.49, 2)

	for i in range(dpq.count()):
		# or dpq.dequeueA()
		print(dpq.dequeueB())

	dpq.enqueue("needle", 1.99, 3)
	dpq.enqueue("syringe", .89, 7)
	dpq.enqueue("plated needle", 2.49, 2)

	# testing dequeueFirst method, should print the 'needle' element.
	print(dpq.dequeueFirst())

def test():
	dpq = DoublePriorityQueue()

	print("Enqueuing...")
	for i in range(100000):
		# random ascii string ranging from 5 to 15 characters long.
		s = ''.join(random.choice(string.ascii_lowercase) for i in range(random.randint(5,15)))
		priorA = random.randint(1,10) * random.random()
		priorB = 37 / random.random()

		dpq.enqueue(s, priorA, priorB)

	print("Done")
	print("There are", dpq.count(), "elements in this queue.")

	print()

	print("Dequeuing...")
	for i in range(dpq.count()):
		dpq.dequeueFirst()

	print("Done")
	print("There are", dpq.count(), "elements in this queue.")

if __name__ == "__main__":
	import timeit
	print("Ran in", timeit.timeit("test()", setup="from __main__ import test", number=1), "seconds.")
