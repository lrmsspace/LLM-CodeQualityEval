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
        # Initialize prefix sum array
        prefix_sum = [0] * (len(nums) + 1)
        for i in range(1, len(nums) + 1):
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1]
        
        # Initialize min_len and min_sum
        min_len = float('inf')
        min_sum = float('inf')
        
        # Iterate through prefix sums
        for right in range(1, len(prefix_sum)):
            # Check if current prefix sum - min_sum >= k
            if prefix_sum[right] - min_sum >= k:
                # Calculate left boundary
                left = right - 1
                # Update min_len and min_sum if necessary
                while left >= 0 and prefix_sum[right] - prefix_sum[left] >= k:
                    min_len = min(min_len, right - left)
                    left -= 1
        
        # Return the result
        return min_len if min_len!= float('inf') else -1
        