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
        arr2.sort()
        n = len(arr1)
        dp = {float('-inf'): 0}
        for i in range(n):
            new_dp = {}
            for x in dp:
                if arr1[i] > x:
                    new_dp[arr1[i]] = min(new_dp.get(arr1[i], float('inf')), dp[x])
                j = bisect.bisect_right(arr2, x)
                if j < len(arr2):
                    new_dp[arr2[j]] = min(new_dp.get(arr2[j], float('inf')), dp[x] + 1)
            dp = new_dp
        return min(dp.values()) if dp else -1        