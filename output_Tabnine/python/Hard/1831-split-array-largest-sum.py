#https://leetcode.com/problems/split-array-largest-sum/
#Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
#Return the minimized largest sum of the split.
#A subarray is a contiguous part of the array.
# 
#Example 1:
#Input: nums = [7,2,5,10,8], k = 2
#Output: 18
#Explanation: There are four ways to split nums into two subarrays.
#The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
#Example 2:
#Input: nums = [1,2,3,4,5], k = 2
#Output: 9
#Explanation: There are four ways to split nums into two subarrays.
#The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
# 
#Constraints:
#	1 <= nums.length <= 1000
#	0 <= nums[i] <= 106
#	1 <= k <= min(50, nums.length)
class Solution(object):
    def splitArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        prefix_sum = [0] * (n + 1)
        for i in range(n):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]
        
        # Initialize a 2D dp table with size (n+1) x (k+1)
        dp = [[float('inf')] * (k + 1) for _ in range(n + 1)]
        
        # Initialize the first row and column of the dp table
        for i in range(n + 1):
            dp[i][1] = prefix_sum[i]
        
        # Fill the dp table
        for i in range(2, k + 1):
            for j in range(i, n + 1):
                for l in range(j - 1, i - 1, -1):
                    dp[j][i] = min(dp[j][i], max(dp[l][i - 1], prefix_sum[j] - prefix_sum[l]))
        
        return dp[n][k]
        