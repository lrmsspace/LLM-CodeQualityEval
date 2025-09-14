#https://leetcode.com/problems/ugly-number-iii/
#An ugly number is a positive integer that is divisible by a, b, or c.
#Given four integers n, a, b, and c, return the nth ugly number.
# 
#Example 1:
#Input: n = 3, a = 2, b = 3, c = 5
#Output: 4
#Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
#Example 2:
#Input: n = 4, a = 2, b = 3, c = 4
#Output: 6
#Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
#Example 3:
#Input: n = 5, a = 2, b = 11, c = 13
#Output: 10
#Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
# 
#Constraints:
#	1 <= n, a, b, c <= 109
#	1 <= a * b * c <= 1018
#	It is guaranteed that the result will be in range [1, 2 * 109].
class Solution(object):
    def nthUglyNumber(self, n, a, b, c):
        """
        :type n: int
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        # Initialize the three pointers for each number
        p2, p3, p5 = 0, 0, 0
        
        # Initialize the ugly number array and the index
        ugly = [0] * n
        ugly[0] = 1
        
        # Loop until we find the nth ugly number
        for i in range(1, n):
            # Find the next ugly number by taking the minimum of the next multiples of a, b, and c
            ugly[i] = min(ugly[p2] * a, ugly[p3] * b, ugly[p5] * c)
            
            # Update the pointer for the next ugly number
            if ugly[i] == ugly[p2] * a:
                p2 += 1
            if ugly[i] == ugly[p3] * b:
                p3 += 1
            if ugly[i] == ugly[p5] * c:
                p5 += 1
        
        # Return the nth ugly number
        return ugly[n - 1]
        