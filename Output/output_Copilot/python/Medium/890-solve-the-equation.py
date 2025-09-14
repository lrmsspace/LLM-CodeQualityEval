#https://leetcode.com/problems/solve-the-equation/
#Solve a given equation and return the value of 'x' in the form of a string "x=#value". The equation contains only '+', '-' operation, the variable 'x' and its coefficient. You should return "No solution" if there is no solution for the equation, or "Infinite solutions" if there are infinite solutions for the equation.
#If there is exactly one solution for the equation, we ensure that the value of 'x' is an integer.
# 
#Example 1:
#Input: equation = "x+5-3+x=6+x-2"
#Output: "x=2"
#Example 2:
#Input: equation = "x=x"
#Output: "Infinite solutions"
#Example 3:
#Input: equation = "2x=x"
#Output: "x=0"
# 
#Constraints:
#	3 <= equation.length <= 1000
#	equation has exactly one '='.
#	equation consists of integers with an absolute value in the range [0, 100] without any leading zeros, and the variable 'x'.
#	The input is generated that if there is a single solution, it will be an integer.
class Solution(object):
    def solveEquation(self, equation):
        """
        :type equation: str
        :rtype: str
        """

        left, right = equation.split('=')

        def parse(expression):
            coeff, constant = 0, 0
            num, sign = 0, 1
            i = 0
            while i < len(expression):
                if expression[i] == '+':
                    constant += sign * num
                    num, sign = 0, 1
                elif expression[i] == '-':
                    constant += sign * num
                    num, sign = 0, -1
                elif expression[i].isdigit():
                    num = num * 10 + int(expression[i])
                elif expression[i] == 'x':
                    if i == 0 or not expression[i - 1].isdigit():
                        coeff += sign
                    else:
                        coeff += sign * num
                        num, sign = 0, 1
                i += 1
                constant += sign * num
            return coeff, constant

        left_coeff, left_const = parse(left)
        right_coeff, right_const = parse(right)

        coeff = left_coeff - right_coeff    
        constant = right_const - left_const

        if coeff == 0:
            if constant == 0:
                return "Infinite solutions"
            else:
                return "No solution"
        else:
            return f"x={constant // coeff}"