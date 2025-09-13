# You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.
# Return the total number of ways to partition nums under this condition.
# Since the answer may be too large, return it modulo 109 + 7.
# Example 1:
# Input: nums = [9,4,1,3,7], k = 4
# Output: 6
# Explanation:
# There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:
# [[9], [4], [1], [3], [7]]
# [[9], [4], [1], [3, 7]]
# [[9], [4], [1, 3], [7]]
# [[9], [4, 1], [3], [7]]
# [[9], [4, 1], [3, 7]]
# [[9], [4, 1, 3], [7]]
# Example 2:
# Input: nums = [3,3,4], k = 0
# Output: 2
# Explanation:
# There are 2 valid partitions that satisfy the given conditions:
# [[3], [3], [4]]
# [[3, 3], [4]]
# Constraints:
# 2 <= nums.length <= 5 * 104
# 1 <= nums[i] <= 109
# 0 <= k <= 109

class Solution(object):
    def countPartitions(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        MOD = 10**9 + 7
        
        prefix_sum = [0] * (n + 1)
        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1]
        
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                for l in range(1, j + 1):
                    if prefix_sum[j] - prefix_sum[l - 1] <= k:
                        dp[i][j] = (dp[i][j] + dp[i - j][j - l]) % MOD  
        return dp[n][n]
        