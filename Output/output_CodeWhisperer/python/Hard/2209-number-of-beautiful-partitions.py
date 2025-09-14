#https://leetcode.com/problems/number-of-beautiful-partitions/
#You are given a string s that consists of the digits '1' to '9' and two integers k and minLength.
#A partition of s is called beautiful if:
#	s is partitioned into k non-intersecting substrings.
#	Each substring has a length of at least minLength.
#	Each substring starts with a prime digit and ends with a non-prime digit. Prime digits are '2', '3', '5', and '7', and the rest of the digits are non-prime.
#Return the number of beautiful partitions of s. Since the answer may be very large, return it modulo 109 + 7.
#A substring is a contiguous sequence of characters within a string.
# 
#Example 1:
#Input: s = "23542185131", k = 3, minLength = 2
#Output: 3
#Explanation: There exists three ways to create a beautiful partition:
#"2354 | 218 | 5131"
#"2354 | 21851 | 31"
#"2354218 | 51 | 31"
#Example 2:
#Input: s = "23542185131", k = 3, minLength = 3
#Output: 1
#Explanation: There exists one way to create a beautiful partition: "2354 | 218 | 5131".
#Example 3:
#Input: s = "3312958", k = 3, minLength = 1
#Output: 1
#Explanation: There exists one way to create a beautiful partition: "331 | 29 | 58".
# 
#Constraints:
#	1 <= k, minLength <= s.length <= 1000
#	s consists of the digits '1' to '9'.
class Solution(object):
    def beautifulPartitions(self, s, k, minLength):
        """
        :type s: str
        :type k: int
        :type minLength: int
        :rtype: int
        """
        prime = {'2', '3', '5', '7'}
        if s[0] not in prime or s[-1] in prime:
            return 0
        dp = [0] * (len(s) + 1)
        dp[0] = 1
        for i in range(len(s)):
            for j in range(i, -1, -1):
                if (i - j + 1 >= minLength and (j == 0 or s[j - 1] not in prime) and s[i] in prime):
                    dp[i + 1] = (dp[i + 1] + dp[j]) % 1000000007
        return dp[len(s)] * (1 if k == 1 else 0)
        