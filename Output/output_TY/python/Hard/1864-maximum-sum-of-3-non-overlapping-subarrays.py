#https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
#Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
#Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
# 
#Example 1:
#Input: nums = [1,2,1,2,6,7,5,1], k = 2
#Output: [0,3,5]
#Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
#We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
#Example 2:
#Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
#Output: [0,2,4]
# 
#Constraints:
#	1 <= nums.length <= 2 * 104
#	1 <= nums[i] < 216
#	1 <= k <= floor(nums.length / 3)
class Solution(object):
    def maxSumOfThreeSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        n = len(nums)
        sum = [0] * (n + 1)
        for i in range(n):
            sum[i + 1] = sum[i] + nums[i]
        dp = [[[0, 0, 0] for _ in range(n + 1)] for _ in range(n + 1)]
        for i in range(1, n + 1):
            dp[0][i][0] = sum[i]
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                for l in range(1, k + 1):
                    dp[i][j][l] = dp[i - 1][j][l]
                    if j >= l:
                        dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - l][l - 1] + sum[j] - sum[j - l])
        return [i - k for i in range(k, n + 1) if dp[n][i][k] == dp[n][n][k]]
