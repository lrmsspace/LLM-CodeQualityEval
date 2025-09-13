#https://leetcode.com/problems/count-special-integers/
#We call a positive integer special if all of its digits are distinct.
#Given a positive integer n, return the number of special integers that belong to the interval [1, n].
# 
#Example 1:
#Input: n = 20
#Output: 19
#Explanation: All the integers from 1 to 20, except 11, are special. Thus, there are 19 special integers.
#Example 2:
#Input: n = 5
#Output: 5
#Explanation: All the integers from 1 to 5 are special.
#Example 3:
#Input: n = 135
#Output: 110
#Explanation: There are 110 integers from 1 to 135 that are special.
#Some of the integers that are not special are: 22, 114, and 131.
# 
#Constraints:
#	1 <= n <= 2 * 109
class Solution(object):
    def countSpecialNumbers(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = str(n)
        @functools.lru_cache(None)
        def f(i, tight, mask):
            if i == len(s):
                return 1 if mask != 0 else 0
            up = int(s[i]) if tight else 9
            res = 0
            for d in range(up + 1):
                if mask & (1 << d) == 0:
                    new_mask = mask if d == 0 and mask == 0 else mask | (1 << d)
                    res += f(i + 1, tight and d == up, new_mask)
            return res
        return f(0, True, 0)
        