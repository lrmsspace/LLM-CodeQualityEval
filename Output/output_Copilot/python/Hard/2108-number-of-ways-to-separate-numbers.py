#https://leetcode.com/problems/number-of-ways-to-separate-numbers/
#You wrote down many positive integers in a string called num. However, you realized that you forgot to add commas to seperate the different numbers. You remember that the list of integers was non-decreasing and that no integer had leading zeros.
#Return the number of possible lists of integers that you could have written down to get the string num. Since the answer may be large, return it modulo 109 + 7.
# 
#Example 1:
#Input: num = "327"
#Output: 2
#Explanation: You could have written down the numbers:
#3, 27
#327
#Example 2:
#Input: num = "094"
#Output: 0
#Explanation: No numbers can have leading zeros and all numbers must be positive.
#Example 3:
#Input: num = "0"
#Output: 0
#Explanation: No numbers can have leading zeros and all numbers must be positive.
# 
#Constraints:
#	1 <= num.length <= 3500
#	num consists of digits '0' through '9'.
class Solution(object):
    def numberOfCombinations(self, num):
        """
        :type num: str
        :rtype: int
        """
        n = len(num)
        mod = 10 ** 9 + 7
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        dp[0][0] = 1

        for i in range(1, n + 1):
            for j in range(1, i + 1):
                if num[i - j] != '0':
                    dp[i][j] = (dp[i][j] + dp[i - j][j]) % mod
                    if j > 1 and num[i - j] == num[i - j + 1]:
                        dp[i][j] = (dp[i][j] + dp[i - j][j - 1]) % mod

        return sum(dp[n]) % mod        