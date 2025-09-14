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
        MOD = 10**9 + 7
        dp = [[0] * (k + 1) for _ in range(len(s) + 1)]
        dp[0][0] = 1
        prime = set('2357')
        for i in range(1, len(s) + 1):
            for j in range(1, min(i, k) + 1):
                if s[i - 1] in prime and i - minLength >= 0:
                    for m in range(max(0, i - minLength), i):
                        if s[m] not in prime:
                            dp[i][j] += dp[m][j - 1]
                            dp[i][j] %= MOD
        return dp[-1][-1]
