# You are given an integer array nums and a positive integer k. Return the sum of the maximum and minimum elements of all subarrays with at most k elements.
# Example 1:
# Input: nums = [1,2,3], k = 2
# Output: 20
# Explanation:
# The subarrays of nums with at most 2 elements are:
# Subarray
# Minimum
# Maximum
# Sum
# [1]
# 1
# 1
# 2
# [2]
# 2
# 2
# 4
# [3]
# 3
# 3
# 6
# [1, 2]
# 1
# 2
# 3
# [2, 3]
# 2
# 3
# 5
# Final Total
# 20
# The output would be 20.
# Example 2:
# Input: nums = [1,-3,1], k = 2
# Output: -6
# Explanation:
# The subarrays of nums with at most 2 elements are:
# Subarray
# Minimum
# Maximum
# Sum
# [1]
# 1
# 1
# 2
# [-3]
# -3
# -3
# -6
# [1]
# 1
# 1
# 2
# [1, -3]
# -3
# 1
# -2
# [-3, 1]
# -3
# 1
# -2
# Final Total
# -6
# The output would be -6.
# Constraints:
# 1 <= nums.length <= 80000
# 1 <= k <= nums.length
# -106 <= nums[i] <= 106

class Solution(object):
    def minMaxSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        max_sum = float('-inf')
        min_sum = float('inf')
        for i in range(n - k + 1):
            current_sum = sum(nums[i:i + k])
            max_sum = max(max_sum, current_sum)
            min_sum = min(min_sum, current_sum)
        return max_sum + min_sum

        