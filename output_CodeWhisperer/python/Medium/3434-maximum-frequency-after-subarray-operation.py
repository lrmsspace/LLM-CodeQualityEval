# You are given an array nums of length n. You are also given an integer k.
# You perform the following operation on nums once:
# Select a subarray nums[i..j] where 0 <= i <= j <= n - 1.
# Select an integer x and add x to all the elements in nums[i..j].
# Find the maximum frequency of the value k after the operation.
# Example 1:
# Input: nums = [1,2,3,4,5,6], k = 1
# Output: 2
# Explanation:
# After adding -5 to nums[2..5], 1 has a frequency of 2 in [1, 2, -2, -1, 0, 1].
# Example 2:
# Input: nums = [10,2,3,4,5,5,4,3,2,2], k = 10
# Output: 4
# Explanation:
# After adding 8 to nums[1..9], 10 has a frequency of 4 in [10, 10, 11, 12, 13, 13, 12, 11, 10, 10].
# Constraints:
# 1 <= n == nums.length <= 105
# 1 <= nums[i] <= 50
# 1 <= k <= 50

class Solution(object):
    def maxFrequency(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        left = 0
        total = 0
        max_freq = 0

        for right in range(len(nums)):
            total += nums[right]
            while (right - left + 1) * nums[right] - total > k:
                total -= nums[left]
                left += 1
            max_freq = max(max_freq, right - left + 1)

        return max_freq        