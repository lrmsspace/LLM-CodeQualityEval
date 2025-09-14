# You are given an integer array nums and two integers k and numOperations.
# You must perform an operation numOperations times on nums, where in each operation you:
# Select an index i that was not selected in any previous operations.
# Add an integer in the range [-k, k] to nums[i].
# Return the maximum possible frequency of any element in nums after performing the operations.
# Example 1:
# Input: nums = [1,4,5], k = 1, numOperations = 2
# Output: 2
# Explanation:
# We can achieve a maximum frequency of two by:
# Adding 0 to nums[1]. nums becomes [1, 4, 5].
# Adding -1 to nums[2]. nums becomes [1, 4, 4].
# Example 2:
# Input: nums = [5,11,20,20], k = 5, numOperations = 1
# Output: 2
# Explanation:
# We can achieve a maximum frequency of two by:
# Adding 0 to nums[1].
# Constraints:
# 1 <= nums.length <= 105
# 1 <= nums[i] <= 105
# 0 <= k <= 105
# 0 <= numOperations <= nums.length

class Solution(object):
    def maxFrequency(self, nums, k, numOperations):
        """
        :type nums: List[int]
        :type k: int
        :type numOperations: int
        :rtype: int
        """
        nums.sort()
        n = len(nums)
        left = 0
        right = 0
        sum = 0
        max_freq = 0
        while right < n:
            sum += nums[right]
            while (right - left + 1) * nums[right] - sum > k:
                sum -= nums[left]
                left += 1
            max_freq = max(max_freq, right - left + 1)
            right += 1
        return max_freq + numOperations        