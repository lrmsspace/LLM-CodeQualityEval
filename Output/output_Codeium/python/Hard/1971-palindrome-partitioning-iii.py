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
        dp = [[0] * n for _ in range(n)]
        for l in range(2, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                dp[i][j] = dp[i + 1][j - 1] + (s[i] != s[j])
        res = 0
        i = 0
        while i < n:
            j = i + k - 1
            if j >= n:
                j = n - 1
            res += dp[i][j]
            i = j + 1
        return res
