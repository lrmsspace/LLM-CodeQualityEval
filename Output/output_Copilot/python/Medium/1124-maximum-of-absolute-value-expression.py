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
        max_val = 0
        n = len(arr1)
        
        for sign1 in [-1, 1]:
            for sign2 in [-1, 1]:
                for sign3 in [-1, 1]:
                    current_val = 0
                    for i in range(n):
                        current_val = max(current_val, abs(sign1 * arr1[i] + sign2 * arr2[i] + sign3 * i))
                    max_val = max(max_val, current_val)
        
        return max_val        