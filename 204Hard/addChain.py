'''
http://www.reddit.com/r/dailyprogrammer/comments/2y5ziw/20150306_challenge_204_hard_addition_chains/
'''

import pdb
import math

length, final = map(int, input().split())

def recurse(nums = [1]):
	#pdb.set_trace()
	for i1 in reversed(range(len(nums))):
		n1 = nums[i1]
		if n1*2**(length+1-len(nums)) < final:
			break
		for n2 in nums[:i1+1]:
			suma = n1 + n2
			if suma < nums[-1]:
				continue
			if len(nums) == length:
				if suma == final:
					return nums + [suma]
				else:
					continue
			result = recurse(nums + [suma])
			if result:
				return result
	return None

print(recurse())



'''
l = []

def f(x, n):
	r = 1
	y = x
	l.append(n)
	while n > 0:
		if n % 2 == 1:
			r *= y
		n //= 2
		y *= y	
		l.append(n)
	return r

def g(a, b):
	r = 1
	l.append(b)
	while 1:
		if b % 2 == 1:
			r *= a
		b =  math.floor(b/2)
		if b == 0:
			break
		a *= a
		l.append(b)

	return r

r = g(2, 25)
l = l[::-1][1:]
l = set(l)
l = list(l)
l.sort()
print(l)
'''
