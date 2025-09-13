#https://leetcode.com/problems/maximum-of-absolute-value-expression/
#Given two arrays of integers with equal lengths, return the maximum value of:
#|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
#where the maximum is taken over all 0 <= i, j < arr1.length.
# 
#Example 1:
#Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
#Output: 13
#Example 2:
#Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
#Output: 20
# 
#Constraints:
#	2 <= arr1.length == arr2.length <= 40000
#	-10^6 <= arr1[i], arr2[i] <= 10^6
class Solution(object):
    def maxAbsValExpr(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        n = len(arr1)
        max_val = float('-inf')
        
        # Iterate through all possible pairs of indices (i, j)
        for i in range(n):
            for j in range(i+1, n):
                # Calculate the absolute values and sum them up
                val = abs(arr1[i] - arr1[j]) + abs(arr2[i] - arr2[j]) + abs(i - j)
                
                # Update the maximum value found so far
                max_val = max(max_val, val)
        
        return max_val
        