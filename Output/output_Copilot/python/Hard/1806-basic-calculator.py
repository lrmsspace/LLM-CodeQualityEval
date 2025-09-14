#https://leetcode.com/problems/basic-calculator/
#Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
#Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
# 
#Example 1:
#Input: s = "1 + 1"
#Output: 2
#Example 2:
#Input: s = " 2-1 + 2 "
#Output: 3
#Example 3:
#Input: s = "(1+(4+5+2)-3)+(6+8)"
#Output: 23
# 
#Constraints:
#	1 <= s.length <= 3 * 105
#	s consists of digits, '+', '-', '(', ')', and ' '.
#	s represents a valid expression.
#	'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
#	'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
#	There will be no two consecutive operators in the input.
#	Every number and running calculation will fit in a signed 32-bit integer.
class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        current_number = 0
        result = 0
        sign = 1  
        # 1. 去除空格
        s = s.replace(" ", "")
        # 2. 遍历字符串
        for char in s:
            if char.isdigit():
                current_number = current_number * 10 + int(char)
            elif char == '+':
                result += sign * current_number
                current_number = 0
                sign = 1
            elif char == '-':
                result += sign * current_number
                current_number = 0
                sign = -1
            elif char == '(':   
                stack.append(result)
                stack.append(sign)
                result = 0
                sign = 1
            elif char == ')':
                result += sign * current_number
                current_number = 0
                result *= stack.pop()  
                result += stack.pop()
        result += sign * current_number
        return result
# Example usage:      