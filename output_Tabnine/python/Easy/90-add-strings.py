#https://leetcode.com/problems/add-strings/
#Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
#You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
# 
#Example 1:
#Input: num1 = "11", num2 = "123"
#Output: "134"
#Example 2:
#Input: num1 = "456", num2 = "77"
#Output: "533"
#Example 3:
#Input: num1 = "0", num2 = "0"
#Output: "0"
# 
#Constraints:
#	1 <= num1.length, num2.length <= 104
#	num1 and num2 consist of only digits.
#	num1 and num2 don't have any leading zeros except for the zero itself.
class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        # Initialize variables
        i, j, carry = len(num1) - 1, len(num2) - 1, 0
        
        # Initialize result string
        result = ""
        
        # Iterate through both strings from right to left
        while i >= 0 or j >= 0 or carry > 0:
            # Calculate the sum of the current digits and carry
            digit1 = int(num1[i]) if i >= 0 else 0
            digit2 = int(num2[j]) if j >= 0 else 0
            sum_digits = digit1 + digit2 + carry
            
            # Update carry
            carry = sum_digits // 10
            
            # Update result string
            result = str(sum_digits % 10) + result
            
            # Move to the next digits
            i -= 1
            j -= 1
        
        return result
        