#https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
#Given an array nums and an integer target, return the maximum number of non-empty non-overlapping subarrays such that the sum of values in each subarray is equal to target.
# 
#Example 1:
#Input: nums = [1,1,1,1,1], target = 2
#Output: 2
#Explanation: There are 2 non-overlapping subarrays [1,1,1,1,1] with sum equals to target(2).
#Example 2:
#Input: nums = [-1,3,5,1,4,2,-9], target = 6
#Output: 2
#Explanation: There are 3 subarrays with sum equal to 6.
#([5,1], [4,2], [3,5,1,4,2,-9]) but only the first 2 are non-overlapping.
# 
#Constraints:
#	1 <= nums.length <= 105
#	-104 <= nums[i] <= 104
#	0 <= target <= 106
class Solution(object):
    def maxNonOverlapping(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # Initialize variables
        dp = [0] * (len(nums) + 1)
        prefix_sum = [0] * (len(nums) + 1)
        
        # Calculate prefix sum
        for i in range(1, len(nums) + 1):
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1]
        
        # Iterate through the prefix sums and update dp array
        for i in range(1, len(nums) + 1):
            for j in range(i - 1, -1, -1):
                if prefix_sum[i] - prefix_sum[j] == target:
                    dp[i] = max(dp[i], dp[j] + 1)
        
        # Return the maximum number of non-overlapping subarrays
        return max(dp)
        