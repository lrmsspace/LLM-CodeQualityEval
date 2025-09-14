#https://leetcode.com/problems/smallest-integer-divisible-by-k/
#Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.
#Return the length of n. If there is no such n, return -1.
#Note: n may not fit in a 64-bit signed integer.
# 
#Example 1:
#Input: k = 1
#Output: 1
#Explanation: The smallest answer is n = 1, which has length 1.
#Example 2:
#Input: k = 2
#Output: -1
#Explanation: There is no such positive integer n divisible by 2.
#Example 3:
#Input: k = 3
#Output: 3
#Explanation: The smallest answer is n = 111, which has length 3.
# 
#Constraints:
#	1 <= k <= 105
class Solution(object):
    def smallestRepunitDivByK(self, k):
        """
        :type k: int
        :rtype: int
        """
        # Initialize the remainder as 0 and the divisor as 1
        remainder, divisor = 0, 1
        
        # Loop until the remainder becomes 0
        while remainder!= 0:
            # Calculate the next digit by taking the remainder when dividing the divisor by 10
            next_digit = remainder * 10 // k
            
            # Update the remainder and divisor
            remainder = remainder * 10 + next_digit
            divisor = divisor * 10 + 1
        
        # If the remainder is 0, return the length of the divisor
        # Otherwise, return -1
        return len(str(divisor)) if remainder == 0 else -1
        