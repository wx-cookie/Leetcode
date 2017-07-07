#!usr/bin/env python
class Solution(object):
	def myPow(self, x, n):
		if n==0:
			return 1
		if n<0:
			return 1.0/self.myPow(x, -n)
		if n==1:
			return x
		res = self.myPow(x, n/2)
		if n%2==1:
			return res*res*x
		else:
			return res*res


if __name__=="__main__":
	so = Solution()
	print so.myPow(2, 3)