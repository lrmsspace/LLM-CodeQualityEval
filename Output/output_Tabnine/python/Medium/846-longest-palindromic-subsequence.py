#https://leetcode.com/problems/longest-palindromic-subsequence/
#Given a string s, find the longest palindromic subsequence's length in s.
#A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
# 
#Example 1:
#Input: s = "bbbab"
#Output: 4
#Explanation: One possible longest palindromic subsequence is "bbbb".
#Example 2:
#Input: s = "cbbd"
#Output: 2
#Explanation: One possible longest palindromic subsequence is "bb".
# 
#Constraints:
#	1 <= s.length <= 1000
#	s consists only of lowercase English letters.
class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Initialize a 2D array dp to store the lengths of longest palindromic subsequences ending at each character.
        # dp[i][j] represents the length of the longest palindromic subsequence in s[i:j+1].
        dp = [[0] * len(s) for _ in range(len(s))]
        
        # Each character is a palindrome of length 1.
        for i in range(len(s)):
            dp[i][i] = 1
        
        # Build up the dp table.
        for length in range(2, len(s) + 1):
            for i in range(len(s) - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])
        
        # Return the length of the longest palindromic subsequence in s.
        return dp[0][len(s) - 1]
