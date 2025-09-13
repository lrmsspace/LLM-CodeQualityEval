#https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
#Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.
#The Fibonacci numbers are defined as:
#	F1 = 1
#	F2 = 1
#	Fn = Fn-1 + Fn-2 for n > 2.
#It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.
# 
#Example 1:
#Input: k = 7
#Output: 2 
#Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
#For k = 7 we can use 2 + 5 = 7.
#Example 2:
#Input: k = 10
#Output: 2 
#Explanation: For k = 10 we can use 2 + 8 = 10.
#Example 3:
#Input: k = 19
#Output: 3 
#Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
# 
#Constraints:
#	1 <= k <= 109
class Solution(object):
    def findMinFibonacciNumbers(self, k):
        """
        :type k: int
        :rtype: int
        """
        # Initialize the first two Fibonacci numbers
        fib1, fib2 = 1, 1
        
        # Initialize the count of Fibonacci numbers
        count = 0
        
        # While the sum of the current Fibonacci numbers is less than or equal to k
        while fib1 + fib2 <= k:
            # Increment the count
            count += 1
            
            # Update the first Fibonacci number to be the second Fibonacci number
            # and the second Fibonacci number to be the sum of the two
            fib1, fib2 = fib2, fib1 + fib2
        
        # Return the count of Fibonacci numbers that sum up to k
        return count
        