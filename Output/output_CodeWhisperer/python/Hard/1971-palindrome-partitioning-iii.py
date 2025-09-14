#https://leetcode.com/problems/palindrome-partitioning-iii/
#You are given a string s containing lowercase letters and an integer k. You need to :
#	First, change some characters of s to other lowercase English letters.
#	Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.
#Return the minimal number of characters that you need to change to divide the string.
# 
#Example 1:
#Input: s = "abc", k = 2
#Output: 1
#Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
#Example 2:
#Input: s = "aabbc", k = 3
#Output: 0
#Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.
#Example 3:
#Input: s = "leetcode", k = 8
#Output: 0
# 
#Constraints:
#	1 <= k <= s.length <= 100.
#	s only contains lowercase English letters.
class Solution(object):
    def palindromePartition(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        n = len(s)
        cost = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    cost[i][j] = cost[i + 1][j - 1]
                else:
                    cost[i][j] = cost[i + 1][j - 1] + 1
        dp = [[float('inf')] * (k + 1) for _ in range(n)]
        for i in range(n):
            dp[i][1] = cost[0][i]
        for i in range(n):
            for j in range(2, min(k, i + 1) + 1):
                for m in range(i):
                    dp[i][j] = min(dp[i][j], dp[m][j - 1] + cost[m + 1][i])
        return dp[n - 1][k]
        