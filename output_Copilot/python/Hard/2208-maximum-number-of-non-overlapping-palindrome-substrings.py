#https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
#You are given a string s and a positive integer k.
#Select a set of non-overlapping substrings from the string s that satisfy the following conditions:
#	The length of each substring is at least k.
#	Each substring is a palindrome.
#Return the maximum number of substrings in an optimal selection.
#A substring is a contiguous sequence of characters within a string.
# 
#Example 1:
#Input: s = "abaccdbbd", k = 3
#Output: 2
#Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
#It can be shown that we cannot find a selection with more than two valid substrings.
#Example 2:
#Input: s = "adbcda", k = 2
#Output: 0
#Explanation: There is no palindrome substring of length at least 2 in the string.
# 
#Constraints:
#	1 <= k <= s.length <= 2000
#	s consists of lowercase English letters.
class Solution(object):
    def maxPalindromes(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        n = len(s)
        dp = [[0] * n for _ in range(n)]    
        for i in range(n):
            dp[i][i] = 1
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        count = 0
        for i in range(n):
            for j in range(i + k - 1, n):
                if dp[i][j] == j - i + 1:
                    count += 1
                    break
        return count    