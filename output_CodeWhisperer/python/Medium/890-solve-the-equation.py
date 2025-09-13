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
        def evaluate(expr):
            x_coeff = 0
            constant = 0
            sign = 1
            num = 0
            for c in expr + '+':
                if c.isdigit():
                    num = num * 10 + int(c)
                elif c == 'x':
                    x_coeff += sign * (num if num else 1)
                    num = 0
                else:
                    constant += sign * num
                    num = 0
                    if c == '-':
                        sign = -1
                    elif c == '+':
                        sign = 1
            return x_coeff, constant
        
        left, right = equation.split('=')
        left_x_coeff, left_constant = evaluate(left)
        right_x_coeff, right_constant = evaluate(right)
        x_coeff = left_x_coeff - right_x_coeff
        constant = right_constant - left_constant
        if x_coeff == 0 and constant == 0:
            return "Infinite solutions"
        elif x_coeff == 0:
            return "No solution"
        else:
            return "x=" + str(constant // x_coeff)
        