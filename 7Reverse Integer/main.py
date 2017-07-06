#!usr/bin/env python

class Solution(object):
	def reverse(self, x):
		flag = 1
		if x < 0:
			flag = -1
			x = -x
		res = 0
		y = 0
		while x>0:
			y = x % 10
			if res*10+y > 2147483647:
				return 0

			res = res*10 + y
			x = x/10
		return res*flag

	def reverse_new(self, x):
		flag = 1 if x>0 else -1
		res, x, y = 0, abs(x), 0
		while x:
			y = x%10
			res = res*10+y
			if res > 2147483647:
				return 0
			x = x/10
		return res*flag

if __name__=='__main__':
	so = Solution()
	print so.reverse_new(21474836475)		