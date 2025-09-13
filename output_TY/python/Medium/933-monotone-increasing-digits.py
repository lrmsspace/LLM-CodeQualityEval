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
        s = str(n)
        for i in range(len(s)-1, 0, -1):
            if s[i] < s[i-1]:
                s = s[:i-1] + str(int(s[i-1])-1) + '9'*(len(s)-i-1)
        return int(s)