#https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
#Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.
# 
#Example 1:
#Input: n = 5
#Output: 5
#Explanation:
#Here are the non-negative integers <= 5 with their corresponding binary representations:
#0 : 0
#1 : 1
#2 : 10
#3 : 11
#4 : 100
#5 : 101
#Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
#Example 2:
#Input: n = 1
#Output: 2
#Example 3:
#Input: n = 2
#Output: 3
# 
#Constraints:
#	1 <= n <= 109
class Solution(object):
    def findIntegers(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [1, 2]
        for i in range(2, 31):
            dp.append(dp[-1] + dp[-2])
        res = 0
        pre = 0
        for i in range(29, -1, -1):
            if n & (1 << i):
                res += dp[i + 1]
                if pre == 1:
                    res -= 1
                    break
                pre = 1
            else:
                pre = 0
        return res + 1

        