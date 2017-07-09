#!usr/bin/env python

class Solution(object):
	def countAndSay(self, n):
		if n==1:
			return "1"

		string = self.countAndSay(n-1) + "*"
		count = 1
		s = ""
		for x in xrange(0, len(string)-1):
			if string[x]==string[x+1]:
				count+=1
			else:
				s = s + str(count) + string[x]
				count = 1
		return s

if __name__=="__main__":
	so = Solution()
	print so.countAndSay(6)