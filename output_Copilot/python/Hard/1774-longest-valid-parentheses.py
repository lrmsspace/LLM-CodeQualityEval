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
        stack = []
        max_length = 0
        last_invalid = -1  
        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)
            else:
                if stack:
                    stack.pop()
                    if stack:
                        max_length = max(max_length, i - stack[-1])
                    else:
                        max_length = max(max_length, i - last_invalid)
                else:
                    last_invalid = i
        return max_length      