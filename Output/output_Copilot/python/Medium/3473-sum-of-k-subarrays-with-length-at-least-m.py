# You are given an integer array nums and two integers, k and m.
# Return the maximum sum of k non-overlapping subarrays of nums, where each subarray has a length of at least m.
# Example 1:
# Input: nums = [1,2,-1,3,3,4], k = 2, m = 2
# Output: 13
# Explanation:
# The optimal choice is:
# Subarray nums[3..5] with sum 3 + 3 + 4 = 10 (length is 3 >= m).
# Subarray nums[0..1] with sum 1 + 2 = 3 (length is 2 >= m).
# The total sum is 10 + 3 = 13.
# Example 2:
# Input: nums = [-10,3,-1,-2], k = 4, m = 1
# Output: -10
# Explanation:
# The optimal choice is choosing each element as a subarray. The output is (-10) + 3 + (-1) + (-2) = -10.
# Constraints:
# 1 <= nums.length <= 2000
# -104 <= nums[i] <= 104
# 1 <= k <= floor(nums.length / m)
# 1 <= m <= 3

class Solution(object):
    def maxSum(self, nums, k, m):
        """
        :type nums: List[int]
        :type k: int
        :type m: int
        :rtype: int
        """
        n = len(nums)
        if k * m > n:
            return -1
        dp = [[-float('inf')] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = 0
        for i in range(1, n + 1):
            for j in range(k + 1):
                dp[i][j] = dp[i - 1][j]
                if j > 0:
                    for l in range(m, i + 1):
                        dp[i][j] = max(dp[i][j], dp[i - l][j - 1] + sum(nums[i - l:i]))
        return max(dp[n]) if max(dp[n]) != -float('inf') else -1
            