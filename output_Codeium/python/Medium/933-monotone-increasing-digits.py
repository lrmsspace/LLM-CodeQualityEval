#https://leetcode.com/problems/monotone-increasing-digits/
#An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
#Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
# 
#Example 1:
#Input: n = 10
#Output: 9
#Example 2:
#Input: n = 1234
#Output: 1234
#Example 3:
#Input: n = 332
#Output: 299
# 
#Constraints:
#	0 <= n <= 109
class Solution(object):
    def monotoneIncreasingDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = list(str(n))
        i = 1
        while i < len(s) and s[i-1] <= s[i]:
            i += 1
        if i < len(s):
            s[i-1] = str(int(s[i-1])-1)
            s[i:] = '9' * (len(s)-i)
        return int(''.join(s))
