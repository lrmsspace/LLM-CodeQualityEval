# You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.
# Example 1:
# Input: nums = [1,4,3,3,2]
# Output: 2
# Explanation:
# The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
# The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
# Hence, we return 2.
# Example 2:
# Input: nums = [3,3,3,3]
# Output: 1
# Explanation:
# The strictly increasing subarrays of nums are [3], [3], [3], and [3].
# The strictly decreasing subarrays of nums are [3], [3], [3], and [3].
# Hence, we return 1.
# Example 3:
# Input: nums = [3,2,1]
# Output: 3
# Explanation:
# The strictly increasing subarrays of nums are [3], [2], and [1].
# The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].
# Hence, we return 3.
# Constraints:
# 1 <= nums.length <= 50
# 1 <= nums[i] <= 50

class Solution(object):
    def longestMonotonicSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        
        max_length = 1
        current_length = 1
        
        # Check for strictly increasing subarrays
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                current_length += 1
            else:
                max_length = max(max_length, current_length)
                current_length = 1
        
        max_length = max(max_length, current_length)
        
        # Reset for strictly decreasing subarrays
        current_length = 1
        
        # Check for strictly decreasing subarrays
        for i in range(1, n):
            if nums[i] < nums[i - 1]:
                current_length += 1
            else:
                max_length = max(max_length, current_length)
                current_length = 1
        
        max_length = max(max_length, current_length)
        
        return max_length
        