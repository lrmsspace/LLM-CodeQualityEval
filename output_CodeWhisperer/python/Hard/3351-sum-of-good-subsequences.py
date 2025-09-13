# You are given an integer array nums. A good subsequence is defined as a subsequence of nums where the absolute difference between any two consecutive elements in the subsequence is exactly 1.
# Return the sum of all possible good subsequences of nums.
# Since the answer may be very large, return it modulo 109 + 7.
# Note that a subsequence of size 1 is considered good by definition.
# Example 1:
# Input: nums = [1,2,1]
# Output: 14
# Explanation:
# Good subsequences are: [1], [2], [1], [1,2], [2,1], [1,2,1].
# The sum of elements in these subsequences is 14.
# Example 2:
# Input: nums = [3,4,5]
# Output: 40
# Explanation:
# Good subsequences are: [3], [4], [5], [3,4], [4,5], [3,4,5].
# The sum of elements in these subsequences is 40.
# Constraints:
# 1 <= nums.length <= 105
# 0 <= nums[i] <= 105

class Solution(object):
    def sumOfGoodSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        n = len(nums)
        dp = [0] * (n + 1)
        dp[0] = 1
        for num in nums:
            new_dp = [0] * (n + 1)
            for i in range(n + 1):
                new_dp[i] = (new_dp[i] + dp[i]) % MOD
                if i > 0:
                    new_dp[i] = (new_dp[i] + dp[i - 1] * num) % MOD
            dp = new_dp
        return sum(dp[1:]) % MOD
    
        