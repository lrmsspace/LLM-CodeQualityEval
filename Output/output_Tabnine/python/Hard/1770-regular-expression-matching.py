#https://leetcode.com/problems/regular-expression-matching/
#Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
#	'.' Matches any single character.​​​​
#	'*' Matches zero or more of the preceding element.
#The matching should cover the entire input string (not partial).
# 
#Example 1:
#Input: s = "aa", p = "a"
#Output: false
#Explanation: "a" does not match the entire string "aa".
#Example 2:
#Input: s = "aa", p = "a*"
#Output: true
#Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
#Example 3:
#Input: s = "ab", p = ".*"
#Output: true
#Explanation: ".*" means "zero or more (*) of any character (.)".
# 
#Constraints:
#	1 <= s.length <= 20
#	1 <= p.length <= 20
#	s contains only lowercase English letters.
#	p contains only lowercase English letters, '.', and '*'.
#	It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        # Initialize a 2D table to store the results of subproblems
        dp = [[False] * (len(p) + 1) for _ in range(len(s) + 1)]
        
        # Base case: when s is empty, only '*' can match it
        for i in range(len(p) + 1):
            dp[0][i] = i == 0 or p[i - 1] == '*'
        
        # Fill the table in bottom-up manner
        for i in range(1, len(s) + 1):
            for j in range(1, len(p) + 1):
                if p[j - 1] == '*':
                    # '*' can match zero or more of the preceding element
                    dp[i][j] = dp[i][j - 2] or (s[i - 1] == p[j - 2] or p[j - 2] == '.') and dp[i - 1][j]
        return dp[len(s)][len(p)]
        