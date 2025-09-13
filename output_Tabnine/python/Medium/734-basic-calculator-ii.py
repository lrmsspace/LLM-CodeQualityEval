#https://leetcode.com/problems/basic-calculator-ii/
#Given a string s which represents an expression, evaluate this expression and return its value. 
#The integer division should truncate toward zero.
#You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
#Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
# 
#Example 1:
#Input: s = "3+2*2"
#Output: 7
#Example 2:
#Input: s = " 3/2 "
#Output: 1
#Example 3:
#Input: s = " 3+5 / 2 "
#Output: 5
# 
#Constraints:
#	1 <= s.length <= 3 * 105
#	s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
#	s represents a valid expression.
#	All the integers in the expression are non-negative integers in the range [0, 231 - 1].
#	The answer is guaranteed to fit in a 32-bit integer.
class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        num = 0
        sign = 1
        i = 0
        
        while i < len(s):
            if s[i].isdigit():
                num = num * 10 + int(s[i])
                i += 1
            elif s[i] =='':
                i += 1
            elif s[i] in '+-*/':
                while stack and stack[-1]!= '(':
                    stack.append(str(num * sign))
                    num = 0
                    sign = 1 if s[i] == '+' else -1 if s[i] == '-' else -sign if s[i] == '*' else 1
                    i += 1
                stack.append(s[i])
                i += 1
            elif s[i] == '(':
                stack.append(s[i])
                i += 1
            elif s[i] == ')':
                while stack and stack[-1]!= '(':
                    stack.append(str(num * sign))
                    num = 0
                    sign = 1
                    stack.pop()
                stack.pop()
                i += 1
                if stack and stack[-1] == '+-*/':
                    stack.append(str(num * sign))
                    num = 0
                    sign = 1 if stack[-1] == '+' else -1 if stack[-1] == '-' else -sign if stack[-1] == '*' else 1
                    stack.pop()
        
        while stack:
            stack.append(str(num * sign))
            num = 0
            sign = 1
            stack.pop()
        
        return int(stack[0])
        