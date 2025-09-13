#https://leetcode.com/problems/find-longest-awesome-substring/
#You are given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps in order to make it a palindrome.
#Return the length of the maximum length awesome substring of s.
# 
#Example 1:
#Input: s = "3242415"
#Output: 5
#Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
#Example 2:
#Input: s = "12345678"
#Output: 1
#Example 3:
#Input: s = "213123"
#Output: 6
#Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists only of digits.
class Solution(object):
    def longestAwesome(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = True
        max_len = 1
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if length % 2 == 0:
                    dp[i][j] = dp[i + 1][j - 1] and s[i] == s[j]
                else:
                    dp[i][j] = (dp[i + 1][j - 1] and s[i] == s[j]) or (dp[i + 1][j] and s[i + 1] == s[j])
                if dp[i][j]:
                    max_len = max(max_len, length)
        return max_len
