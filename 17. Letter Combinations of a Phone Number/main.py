#!usr/bin/env python
class Solution(object):
	def letterCombinations(self, digits):
		nums = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
		res = []
		res_string=[]
		for digit in digits:
			res_string.append(nums[digit])

		for i in range(len(res_string)):
			for s in res_string[i]:
