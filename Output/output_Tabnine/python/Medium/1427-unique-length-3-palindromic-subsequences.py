#https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
#Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
#Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
#A palindrome is a string that reads the same forwards and backwards.
#A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
#	For example, "ace" is a subsequence of "abcde".
# 
#Example 1:
#Input: s = "aabca"
#Output: 3
#Explanation: The 3 palindromic subsequences of length 3 are:
#- "aba" (subsequence of "aabca")
#- "aaa" (subsequence of "aabca")
#- "aca" (subsequence of "aabca")
#Example 2:
#Input: s = "adc"
#Output: 0
#Explanation: There are no palindromic subsequences of length 3 in "adc".
#Example 3:
#Input: s = "bbcbaba"
#Output: 4
#Explanation: The 4 palindromic subsequences of length 3 are:
#- "bbb" (subsequence of "bbcbaba")
#- "bcb" (subsequence of "bbcbaba")
#- "bab" (subsequence of "bbcbaba")
#- "aba" (subsequence of "bbcbaba")
# 
#Constraints:
#	3 <= s.length <= 105
#	s consists of only lowercase English letters.
class Solution(object):
    def countPalindromicSubsequence(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Initialize a 3D array dp to store the number of palindromic subsequences of length i ending at index j
        # dp[i][j][k] represents the number of palindromic subsequences of length i ending at index j with k distinct characters
        dp = [[[0] * 27 for _ in range(len(s) + 1)] for _ in range(3)]
        
        # Initialize the base case: dp[0][i][0] = 1 for all i
        for i in range(len(s) + 1):
            dp[0][i][0] = 1
        
        # Iterate through the string and update the dp array
        for i in range(1, 3 + 1):
            for j in range(1, len(s) + 1):
                for k in range(1, 27):
                    # If the current character in the string is the kth distinct character, update the dp array
                    if s[j - 1] == chr(k + ord('a')):
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + dp[i][j - 1][k] + dp[i][j - 1][k - 1]
                    else:
                        dp[i][j][k] = dp[i][j - 1][k]
        
        # Return the number of palindromic subsequences of length 3
        return sum(dp[3])
        