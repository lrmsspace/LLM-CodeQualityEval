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
        
        # 统计每个数字出现的次数
        count = {}
        
        # dp[i] 表示以值i结尾的所有好子序列的和
        dp = {}
        
        result = 0
        
        for num in nums:
            # 初始情况下，单独这个元素构成的子序列
            dp[num] = num
            
            # 可以与前面值为num-1的子序列连接
            if num - 1 in dp:
                dp[num] += dp[num - 1]
                dp[num] %= MOD
            
            # 计算结果
            result = (result + dp[num]) % MOD
        
        return result