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
# 1 <= nums.length <= 500
# 1 <= nums[i] <= 109
# 0 <= k <= min(nums.length, 25)

class Solution(object):
    def maximumLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        dp = [[2] * (k + 1) for _ in range(n)]
        mp = {}
        ans = 1
        
        for i in range(n):
            mp[nums[i]] = i
            for j in range(k + 1):
                if nums[i] in mp and mp[nums[i]] < i:
                    dp[i][j] = dp[mp[nums[i]]][j] + 1
                if j > 0:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1)
                ans = max(ans, dp[i][j])
        
        return ans
            