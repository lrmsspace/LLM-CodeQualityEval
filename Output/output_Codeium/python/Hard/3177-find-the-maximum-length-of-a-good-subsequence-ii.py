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
        dp = [1] * len(nums)
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                dp[i] = dp[i - 1] + 1
            else:
                dp[i] = dp[i - 1]
            if k > 0:
                j = i - k
                while j >= 0 and nums[j] != nums[i]:
                    j += 1
                if j >= 0:
                    dp[i] = max(dp[i], dp[j] + i - j)
        return max(dp)
