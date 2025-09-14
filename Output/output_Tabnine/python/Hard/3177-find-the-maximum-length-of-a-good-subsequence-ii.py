# You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
# Return the maximum possible length of a good subsequence of nums.
# Example 1:
# Input: nums = [1,2,1,1,3], k = 2
# Output: 4
# Explanation:
# The maximum length subsequence is [1,2,1,1,3].
# Example 2:
# Input: nums = [1,2,3,4,5,1], k = 0
# Output: 2
# Explanation:
# The maximum length subsequence is [1,2,3,4,5,1].
# Constraints:
# 1 <= nums.length <= 5 * 103
# 1 <= nums[i] <= 109
# 0 <= k <= min(50, nums.length)

class Solution(object):
    def maximumLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        dp = [0] * n
        left = [0] * n
        right = [0] * n
        
        for i in range(1, n):
            if nums[i] > nums[i-1]:
                dp[i] = dp[i-1] + 1
        
        for i in range(n-2, -1, -1):
            if nums[i] < nums[i+1]:
                right[i] = right[i+1] + 1
        
        max_len = 0
        for i in range(n):
            if nums[i] < nums[i+1]:
                max_len = max(max_len, dp[i] + right[i+1])
        
        return max_len + k
        