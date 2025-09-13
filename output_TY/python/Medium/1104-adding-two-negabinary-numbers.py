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
        i, j = len(arr1) - 1, len(arr2) - 1
        carry = 0
        ans = []
        while i >= 0 or j >= 0 or carry:
            x = carry
            if i >= 0:
                x += arr1[i]
            if j >= 0:
                x += arr2[j]
            carry, val = divmod(x, -2)
            if val == -1:
                val = 1
                carry += 1
            ans.append(val)
            i -= 1
            j -= 1
        while len(ans) > 1 and ans[-1] == 0:
            ans.pop()
        return ans[::-1]