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
        # Initialize an empty string to store the result
        result = ""
        
        # Initialize carry to 0
        carry = 0
        
        # Reverse both strings to make addition easier from the least significant digit
        num1 = num1[::-1]
        num2 = num2[::-1]
        
        # Get the maximum length of the two numbers
        max_length = max(len(num1), len(num2))
        
        # Loop through each digit position
        for i in range(max_length):
            # Get the current digits, or 0 if one number is shorter
            digit1 = int(num1[i]) if i < len(num1) else 0
            digit2 = int(num2[i]) if i < len(num2) else 0
            
            # Calculate the sum of the digits and the carry
            total = digit1 + digit2 + carry
            
            # Update carry for the next position
            carry = total // 10
            
            # Append the last digit of total to the result string
            result += str(total % 10)
        
        # If there's a carry left after the last addition, append it to the result
        if carry:
            result += str(carry)
        
        # Reverse the result string to get the final answer and return it
        return result[::-1]        