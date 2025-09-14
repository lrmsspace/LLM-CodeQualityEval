#https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
#Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.
#Note that the subarray needs to be non-empty after deleting one element.
# 
#Example 1:
#Input: arr = [1,-2,0,3]
#Output: 4
#Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
#Example 2:
#Input: arr = [1,-2,-2,3]
#Output: 3
#Explanation: We just choose [3] and it's the maximum sum.
#Example 3:
#Input: arr = [-1,-1,-1,-1]
#Output: -1
#Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
# 
#Constraints:
#	1 <= arr.length <= 105
#	-104 <= arr[i] <= 104
class Solution(object):
    def maximumSum(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n = len(arr)
        dp = [[0,0] for _ in range(n)]
        dp[0][0] = arr[0]
        dp[0][1] = arr[0]
        for i in range(1,n):
            dp[i][0] = max(dp[i-1][0]+arr[i],arr[i])
            dp[i][1] = max(dp[i-1][1]+arr[i],dp[i][0])
        return max(dp[n-1][0],dp[n-1][1])
        