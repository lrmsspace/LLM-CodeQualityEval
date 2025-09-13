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
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            j = i
            while j > 0 and num[j - 1] == '0':
                j -= 1
            k = j
            while k > 0 and int(num[k - 1:i]) <= int(num[i - j:i]):
                k -= 1
            dp[i] = sum(dp[k:i])
        return dp[n] % (10 ** 9 + 7)