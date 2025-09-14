# You are given a 0-indexed array nums consisting of positive integers.
# A partition of an array into one or more contiguous subarrays is called good if no two subarrays contain the same number.
# Return the total number of good partitions of nums.
# Since the answer may be large, return it modulo 109 + 7.
# Example 1:
# Input: nums = [1,2,3,4]
# Output: 8
# Explanation: The 8 possible good partitions are: ([1], [2], [3], [4]), ([1], [2], [3,4]), ([1], [2,3], [4]), ([1], [2,3,4]), ([1,2], [3], [4]), ([1,2], [3,4]), ([1,2,3], [4]), and ([1,2,3,4]).
# Example 2:
# Input: nums = [1,1,1,1]
# Output: 1
# Explanation: The only possible good partition is: ([1,1,1,1]).
# Example 3:
# Input: nums = [1,2,1,3]
# Output: 2
# Explanation: The 2 possible good partitions are: ([1,2,1], [3]) and ([1,2,1,3]).
# Constraints:
# 1 <= nums.length <= 105
# 1 <= nums[i] <= 109

class Solution(object):
    def numberOfGoodPartitions(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        n = len(nums)
        dp = [0] * (n + 1)
        dp[0] = 1
        last_seen = {}
        for i in range(1, n + 1):
            dp[i] = (dp[i - 1] * 2) % MOD
            if nums[i - 1] in last_seen:
                dp[i] = (dp[i] - dp[last_seen[nums[i - 1]]] + MOD) % MOD
            last_seen[nums[i - 1]] = i - 1
        return dp[n]
