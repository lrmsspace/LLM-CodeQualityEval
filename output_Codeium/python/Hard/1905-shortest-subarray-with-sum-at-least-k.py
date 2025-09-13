#https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
#Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
#A subarray is a contiguous part of an array.
# 
#Example 1:
#Input: nums = [1], k = 1
#Output: 1
#Example 2:
#Input: nums = [1,2], k = 4
#Output: -1
#Example 3:
#Input: nums = [2,-1,2], k = 3
#Output: 3
# 
#Constraints:
#	1 <= nums.length <= 105
#	-105 <= nums[i] <= 105
#	1 <= k <= 109
class Solution(object):
    def shortestSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        prefix_sum = [0]
        for num in nums:
            prefix_sum.append(prefix_sum[-1] + num)
        res = float('inf')
        for i in range(len(nums)):
            for j in range(i + 1, len(nums) + 1):
                if prefix_sum[j] - prefix_sum[i] >= k:
                    res = min(res, j - i)
        return res if res != float('inf') else -1
