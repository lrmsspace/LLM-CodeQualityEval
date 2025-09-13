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
        res = 0
        for p, q in [[1, 1], [1, -1], [-1, 1], [-1, -1]]:
            smallest = p * arr1[0] + q * arr2[0] + 0
            for i in range(n):
                cur = p * arr1[i] + q * arr2[i] + i
                res = max(res, cur - smallest)
                smallest = min(smallest, cur)
        return res
        