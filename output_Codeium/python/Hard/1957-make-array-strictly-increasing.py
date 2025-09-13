#https://leetcode.com/problems/make-array-strictly-increasing/
#Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
#In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
#If there is no way to make arr1 strictly increasing, return -1.
# 
#Example 1:
#Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
#Output: 1
#Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
#Example 2:
#Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
#Output: 2
#Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
#Example 3:
#Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
#Output: -1
#Explanation: You can't make arr1 strictly increasing.
# 
#Constraints:
#	1 <= arr1.length, arr2.length <= 2000
#	0 <= arr1[i], arr2[i] <= 10^9
# 
class Solution(object):
    def makeArrayIncreasing(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        dp = [float('inf')] * (len(arr1) + 1)
        dp[0] = 0
        for i in range(len(arr1)):
            for j in range(len(arr2)):
                if arr1[i] >= arr2[j]: continue
                dp[i+1] = min(dp[i+1], dp[i] + 1)
            if i > 0 and arr1[i] <= arr1[i-1]: continue
            dp[i+1] = min(dp[i+1], dp[i])
        return dp[-1] if dp[-1] != float('inf') else -1
