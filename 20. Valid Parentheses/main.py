#! usr/bin/env python
class Solution(object):
	"""docstring for Solution"""
	def isValid(self, s):
		left = ['(', '[', '{']
		right = [')', ']', '}']
		stac = []
		for char_s in s:
			if char_s in left:
				stac.append(char_s)
			else:
				index = right.index(char_s)
				if stac == []:
					return False
				if stac[-1] == left[index]:
					stac.pop()
				else:
					return False
		return True if stac==[] else False


if __name__=='__main__':
	so = Solution()
	print so.isValid(']')
