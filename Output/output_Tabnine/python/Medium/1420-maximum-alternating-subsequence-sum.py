#https://leetcode.com/problems/maximum-alternating-subsequence-sum/
#The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices.
#	For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
#Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence).
#A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.
# 
#Example 1:
#Input: nums = [4,2,5,3]
#Output: 7
#Explanation: It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7.
#Example 2:
#Input: nums = [5,6,7,8]
#Output: 8
#Explanation: It is optimal to choose the subsequence [8] with alternating sum 8.
#Example 3:
#Input: nums = [6,2,1,2,4,5]
#Output: 10
#Explanation: It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10.
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i] <= 105
class Solution(object):

    def maxAlternatingSum(self, nums):

        """

        :type nums: List[int]

        :rtype: int

        """
        # Initialize the dp array with zeros
        dp = [0] * len(nums)
        # Initialize the prefix_sum array with zeros

        prefix_sum = [0] * len(nums)
        # Calculate the prefix sum array
        prefix_sum[0] = nums[0]
        for i in range(1, len(nums)):
            prefix_sum[i] = prefix_sum[i-1] + nums[i]
        # Calculate the maximum alternating sum by iterating through the dp array
        dp[0] = prefix_sum[0]
        dp[1] = max(prefix_sum[0], prefix_sum[1])
        for i in range(2, len(nums)):
            dp[i] = max(dp[i-1], prefix_sum[i] - dp[i-2])
        # Return the maximum alternating sum
        return dp[-1]
