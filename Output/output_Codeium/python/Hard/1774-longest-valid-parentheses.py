#https://leetcode.com/problems/longest-valid-parentheses/
#Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
# 
#Example 1:
#Input: s = "(()"
#Output: 2
#Explanation: The longest valid parentheses substring is "()".
#Example 2:
#Input: s = ")()())"
#Output: 4
#Explanation: The longest valid parentheses substring is "()()".
#Example 3:
#Input: s = ""
#Output: 0
# 
#Constraints:
#	0 <= s.length <= 3 * 104
#	s[i] is '(', or ')'.
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [0] * n
        res = 0
        for i in range(1, n):
            if s[i] == ')':
                if s[i-1] == '(':
                    dp[i] = dp[i-2] + 2 if i >= 2 else 2
                elif i-dp[i-1] > 0 and s[i-dp[i-1]-1] == '(':
                    dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2 if i-dp[i-1] >= 2 else dp[i-1] + 2
                res = max(res, dp[i])
        return res
