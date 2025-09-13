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
        # Initialize a set to store unique palindromic subsequences of length 3
        palindromic_subsequences = set()
        
        # Iterate through the string to find unique characters
        for i in range(len(s)):
            for j in range(i + 1, len(s)):
                if s[i] == s[j]:        
                    # If characters at i and j are the same, check for a character in between
                    for k in range(i + 1, j):
                        palindromic_subsequences.add(s[i] + s[k] + s[j])
                    break
        # Return the count of unique palindromic subsequences of length 3
        return len(palindromic_subsequences)