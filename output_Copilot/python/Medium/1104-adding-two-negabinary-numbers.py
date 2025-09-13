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
        # Convert arr1 and arr2 to decimal
        num1 = 0
        num2 = 0
        for i in range(len(arr1)):
            num1 += arr1[i] * (-2) ** (len(arr1) - i - 1)
        for i in range(len(arr2)):
            num2 += arr2[i] * (-2) ** (len(arr2) - i - 1)

        # Add the two numbers
        result = num1 + num2

        # Convert the result back to negabinary
        if result == 0:
            return [0]

        negabinary = []
        while result != 0:
            result, remainder = divmod(result, -2)
            if remainder < 0:
                remainder += 2
                result += 1
            negabinary.append(remainder)

        return negabinary[::-1]        