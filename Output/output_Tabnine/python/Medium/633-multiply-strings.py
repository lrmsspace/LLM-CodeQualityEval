#https://leetcode.com/problems/multiply-strings/
#Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
#Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
# 
#Example 1:
#Input: num1 = "2", num2 = "3"
#Output: "6"
#Example 2:
#Input: num1 = "123", num2 = "456"
#Output: "56088"
# 
#Constraints:
#	1 <= num1.length, num2.length <= 200
#	num1 and num2 consist of digits only.
#	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        # Initialize result with zeros
        result = [0] * (len(num1) + len(num2))
        
        # Traverse the digits from right to left
        for i in range(len(num1) - 1, -1, -1):
            for j in range(len(num2) - 1, -1, -1):
                # Calculate the product of the current digits and the multiplier
                product = int(num1[i]) * int(num2[j])
                
                # Calculate the carry
                carry = result[i + j + 1] + product // 10
                
                # Update the current digit in the result
                result[i + j + 1] = product % 10
                
                # Add the carry to the next digit
                result[i + j] += carry
        
        # Remove leading zeros from the result
        i = 0
        while i < len(result) - 1 and result[i] == 0:
            i += 1
        
        # Convert the result to a string and return
        return ''.join(map(str, result[i:]))
        