#https://leetcode.com/problems/numbers-with-repeated-digits/
#Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.
# 
#Example 1:
#Input: n = 20
#Output: 1
#Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
#Example 2:
#Input: n = 100
#Output: 10
#Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
#Example 3:
#Input: n = 1000
#Output: 262
# 
#Constraints:
#	1 <= n <= 109
class Solution(object):
    def numDupDigitsAtMostN(self, n):
        """
        :type n: int
        :rtype: int
        """
        n = str(n)
        # dp[i][j][k] stands for the number of i-digit numbers that has at most k repeated digits and the last digit is j
        dp = [[[0, 0] for _ in range(10)] for _ in range(len(n) + 1)]
        dp[0][0][0] = 1
        for i in range(1, len(n) + 1):
            for j in range(10):
                if i == 1 or j != int(n[i - 2]):
                    dp[i][j][0] += sum(dp[i - 1][k][0] for k in range(10) if k != j)
                dp[i][j][1] += dp[i - 1][j][1] + sum(dp[i - 1][k][0] for k in range(10) if k != j)
        return sum(dp[-1][int(n[-1])][1] for k in range(10))
