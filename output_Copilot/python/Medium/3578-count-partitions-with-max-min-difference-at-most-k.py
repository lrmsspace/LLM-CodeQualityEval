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
        MOD = 10**9 + 7
        n = len(nums)
        dp = [0] * (n + 1)
        dp[0] = 1

        for i in range(1, n + 1):
            current_max = nums[i - 1]
            current_min = nums[i - 1]
            for j in range(i - 1, -1, -1):
                current_max = max(current_max, nums[j])
                current_min = min(current_min, nums[j])
                if current_max - current_min > k:
                    break
                dp[i] = (dp[i] + dp[j]) % MOD

        return dp[n]
