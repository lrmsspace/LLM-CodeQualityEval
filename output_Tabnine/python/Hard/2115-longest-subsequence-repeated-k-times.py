#https://leetcode.com/problems/longest-subsequence-repeated-k-times/
#You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.
#A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
#A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.
#	For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
#Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.
# 
#Example 1:
#Input: s = "letsleetcode", k = 2
#Output: "let"
#Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
#"let" is the lexicographically largest one.
#Example 2:
#Input: s = "bb", k = 2
#Output: "b"
#Explanation: The longest subsequence repeated 2 times is "b".
#Example 3:
#Input: s = "ab", k = 2
#Output: ""
#Explanation: There is no subsequence repeated 2 times. Empty string is returned.
# 
#Constraints:
#	n == s.length
#	2 <= n, k <= 2000
#	2 <= n < k * 8
#	s consists of lowercase English letters.
class Solution(object):
    def longestSubsequenceRepeatedK(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        # Initialize an empty dictionary to store the longest subsequence repeated k times
        longest_subsequences = {}
        
        # Iterate through the string s
        for i in range(len(s)):
            # Check if the subsequence repeated k times is already in the dictionary
            if s[i] * k in longest_subsequences:
                # If it is, update the longest subsequence if necessary
                if len(longest_subsequences[s[i] * k]) < len(s[i:]):
                    longest_subsequences[s[i] * k] = s[i:]
            else:
                # If it is not, add it to the dictionary with the current subsequence
                longest_subsequences[s[i] * k] = s[i:]
        
        # Return the lexicographically largest subsequence repeated k times
        return max(longest_subsequences.values(), key=len) if longest_subsequences else ""
        