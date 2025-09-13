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
        current_number = 0
        operation = '+'
        s = s.replace(' ', '')  
        for i in range(len(s)):
            char = s[i]
            if char.isdigit():
                current_number = current_number * 10 + int(char)
            if char in '+-*/' or i == len(s) - 1:
                if operation == '+':
                    stack.append(current_number)
                elif operation == '-':
                    stack.append(-current_number)
                elif operation == '*':
                    stack[-1] *= current_number
                elif operation == '/':
                    stack[-1] = int(stack[-1] / current_number)
                operation = char
                current_number = 0
        return sum(stack)      