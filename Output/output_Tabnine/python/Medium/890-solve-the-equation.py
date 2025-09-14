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
        left, right = left.split('x'), right.split('x')
        
        if left[0] == '' and right[0] == '':
            return 'Infinite solutions'
        
        if left[0] == '' or right[0] == '':
            if left[0] == '':
                return 'x=' + str(int(right[0]) // int(left[1]) if left[1]!= '0' else 'Infinite solutions')
            else:
                return 'x=' + str(int(left[0]) // int(right[1]) if right[1]!= '0' else 'Infinite solutions')
        
        if left[1] == '0' and right[1] == '0':
            return 'No solution'
        
        if left[1]!= '0' and right[1]!= '0':
            return 'x=' + str((int(right[0]) - int(left[0])) // (int(left[1]) - int(right[1])))
        
        
        