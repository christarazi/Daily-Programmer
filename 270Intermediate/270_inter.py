'''
https://www.reddit.com/r/dailyprogrammer/comments/4n6hc2/20160608_challenge_270_intermediate_generating/
'''

import sys, collections, random
from pprint import pprint
print("Starting...")

# prefix length
n = 2

userInput = "".join(sys.stdin.readlines()).strip().replace('\n', '')
words = userInput.split(' ')
last_word = len(words) - 1

freqTable = collections.defaultdict(list)
freqTable[("", "")].append((words[0], 1))
freqTable[("", words[0])].append((words[1], 1))
freqTable[(words[-2], words[-1])].append(("", 1))

for i in range(len(words) - 1):
	if i + 1 == last_word:
		break
	else:
		tmp_list = freqTable[(words[i], words[i+1])]
		for index, elem in enumerate(tmp_list):
			if words[i+2] == elem[0]:
				tmp_list.append((words[i+2], elem[1] + 1))
				del tmp_list[index]
				break
		else:
			freqTable[(words[i], words[i+1])].append((words[i+2], 1))
	
pprint(freqTable)
print()

prefix = ("", "")
suffix = freqTable[prefix][0]
while suffix[0] != "":
	print(suffix[0], "", end='')
	prefix = (prefix[1], suffix[0])
	suffix = random.choice(freqTable[prefix])
print()
