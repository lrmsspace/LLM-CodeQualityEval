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
        stack = [-1]
        max_len = 0
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    max_len = max(max_len, i - stack[-1])
        return max_len 