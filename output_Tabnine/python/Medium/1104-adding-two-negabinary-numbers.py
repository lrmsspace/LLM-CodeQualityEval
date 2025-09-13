#https://leetcode.com/problems/adding-two-negabinary-numbers/
#Given two numbers arr1 and arr2 in base -2, return the result of adding them together.
#Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array, format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.
#Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.
# 
#Example 1:
#Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
#Output: [1,0,0,0,0]
#Explanation: arr1 represents 11, arr2 represents 5, the output represents 16.
#Example 2:
#Input: arr1 = [0], arr2 = [0]
#Output: [0]
#Example 3:
#Input: arr1 = [0], arr2 = [1]
#Output: [1]
# 
#Constraints:
#	1 <= arr1.length, arr2.length <= 1000
#	arr1[i] and arr2[i] are 0 or 1
#	arr1 and arr2 have no leading zeros
class Solution(object):
    def addNegabinary(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        # Initialize result list
        result = []
        
        # Initialize carry
        carry = 0
        
        # Iterate over the numbers from the end of both arrays
        i, j = len(arr1) - 1, len(arr2) - 1
        
        # Iterate until we reach the beginning of either array
        while i >= 0 or j >= 0:
            
            # Add the current digits of arr1 and arr2 and add the carry
            digit1 = arr1[i] if i >= 0 else 0
            digit2 = arr2[j] if j >= 0 else 0
            
            # Calculate the sum and the carry
            sum_digits = digit1 + digit2 + carry
            
            # If the sum is greater than or equal to 2, set carry to 1 and the digit to 0
            if sum_digits >= 2:
                carry = 1
                digit = 0
            else:
                carry = 0
        # If there is still a carry, add it to the result
        if carry:
            result.append(carry)
        
        # Reverse the result list and return it
        return result[::-1]

        