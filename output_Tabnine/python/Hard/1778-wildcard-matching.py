#https://leetcode.com/problems/wildcard-matching/
#Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
#	'?' Matches any single character.
#	'*' Matches any sequence of characters (including the empty sequence).
#The matching should cover the entire input string (not partial).
# 
#Example 1:
#Input: s = "aa", p = "a"
#Output: false
#Explanation: "a" does not match the entire string "aa".
#Example 2:
#Input: s = "aa", p = "*"
#Output: true
#Explanation: '*' matches any sequence.
#Example 3:
#Input: s = "cb", p = "?a"
#Output: false
#Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
# 
#Constraints:
#	0 <= s.length, p.length <= 2000
#	s contains only lowercase English letters.
#	p contains only lowercase English letters, '?' or '*'.
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        # Initialize memoization table
        memo = [[False] * (len(p) + 1) for _ in range(len(s) + 1)]
        
        # Initialize base cases
        memo[0][0] = True
        for i in range(2, len(p) + 1):
            if p[i - 1] == '*':
                memo[0][i] = memo[0][i - 2]
        
        # Fill the memoization table
        for i in range(1, len(s) + 1):
            for j in range(1, len(p) + 1):
                if p[j - 1] == '*':
                    memo[i][j] = memo[i][j - 2] or (s[i - 1] == p[j - 2] or p[j - 2] == '?') and memo[i - 1][j]
        return memo[len(s)][len(p)]
        
        