#https://leetcode.com/problems/add-two-integers/
#Given two integers num1 and num2, return the sum of the two integers.
# 
#Example 1:
#Input: num1 = 12, num2 = 5
#Output: 17
#Explanation: num1 is 12, num2 is 5, and their sum is 12 + 5 = 17, so 17 is returned.
#Example 2:
#Input: num1 = -10, num2 = 4
#Output: -6
#Explanation: num1 + num2 = -6, so -6 is returned.
# 
#Constraints:
#	-100 <= num1, num2 <= 100
class Solution(object):
    def sum(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        # Continue the addition until there is no carry left
        while num2!= 0:
            # Calculate the carry
            carry = num1 & num2
            
            # Calculate the sum without carry
            num1 = num1 ^ num2
            
            # Shift the carry to the left by 1 bit
            num2 = carry << 1
        
        return num1
        