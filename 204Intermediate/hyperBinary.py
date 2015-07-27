'''
http://www.reddit.com/r/dailyprogrammer/comments/2xx86n/20150302_challenge_204_intermediate_its_like/
'''

results = []
def hyperBinary(n, s="", m=1):
	if n == 0:
		results.append(s)
		return

	if m > n:
		return 

	if n % (m*2) == 0:
		# each call here diverges into its own path
		hyperBinary(n, "0"+s, (m*2))		
		hyperBinary(n-(m*2), "2"+s, (m*2))
	else:
		hyperBinary((n-m), "1"+s, (m*2))

hyperBinary(12345678910)
print(len(results))
