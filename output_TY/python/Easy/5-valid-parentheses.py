#https://leetcode.com/problems/valid-parentheses/
#Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#An input string is valid if:
#	Open brackets must be closed by the same type of brackets.
#	Open brackets must be closed in the correct order.
#	Every close bracket has a corresponding open bracket of the same type.
# 
#Example 1:
#Input: s = "()"
#Output: true
#Example 2:
#Input: s = "()[]{}"
#Output: true
#Example 3:
#Input: s = "(]"
#Output: false
#Example 4:
#Input: s = "([])"
#Output: true
# 
#Constraints:
#	1 <= s.length <= 104
#	s consists of parentheses only '()[]{}'.
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for char in s:
            if char in ['(','[','{']:
                stack.append(char)
            else:
                if len(stack) == 0:
                    return False
                else:
                    if char == ')':
                        if stack[-1] == '(':
                            stack.pop()
                        else:
                            return False
                    elif char == ']':
                        if stack[-1] == '[':
                            stack.pop()
                        else:
                            return False
                    elif char == '}':
                        if stack[-1] == '{':
                           stack.pop()  
                        else:
                               return False
        return len(stack) == 0