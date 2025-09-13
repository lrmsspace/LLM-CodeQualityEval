#https://leetcode.com/problems/clumsy-factorial/
#The factorial of a positive integer n is the product of all positive integers less than or equal to n.
#	For example, factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.
#We make a clumsy factorial using the integers in decreasing order by swapping out the multiply operations for a fixed rotation of operations with multiply '*', divide '/', add '+', and subtract '-' in this order.
#	For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.
#However, these operations are still applied using the usual order of operations of arithmetic. We do all multiplication and division steps before any addition or subtraction steps, and multiplication and division steps are processed left to right.
#Additionally, the division that we use is floor division such that 10 * 9 / 8 = 90 / 8 = 11.
#Given an integer n, return the clumsy factorial of n.
# 
#Example 1:
#Input: n = 4
#Output: 7
#Explanation: 7 = 4 * 3 / 2 + 1
#Example 2:
#Input: n = 10
#Output: 12
#Explanation: 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
# 
#Constraints:
#	1 <= n <= 104
class Solution(object):
    def clumsy(self, n):
        """
        :type n: int
        :rtype: int
        """
        stack = []
        ops = ['*', '/', '+', '-']
        for i in range(n, 0, -1):
            stack.append(i)
            if len(stack) >= 3:
                op = ops.pop(0)
                num2 = stack.pop()
                num1 = stack.pop()
                if op == '*':
                    stack.append(num1 * num2)
                elif op == '/':
                    stack.append(int(num1 / num2))
                elif op == '+':
                    stack.append(num1 + num2)
                else:
                    stack.append(num1 - num2)
        
        return stack[0]
        