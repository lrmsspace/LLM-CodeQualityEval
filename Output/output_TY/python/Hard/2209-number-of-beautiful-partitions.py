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
        n = len(s)
        primes = [False, False] + [True] * (n - 1)
        for i in range(2, int(n ** 0.5) + 1):
            if primes[i]:
                for j in range(i * i, n + 1, i):
                    primes[j] = False
        prime = [primes[int(s[i])] for i in range(n)]
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            if prime[i - 1]:
                for j in range(1, k + 1):
                    dp[i][j] += dp[i - 1][j - 1]
            if i >= minLength and not prime[i - minLength]:
                for j in range(1, k):
                    dp[i][j] += dp[i - minLength][j - 1]
        return sum(dp[n][k:]) % (10 ** 9 + 7)