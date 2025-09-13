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
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        dp = [[0] * (k + 1) for _ in range(3)]
        dp[0][0] = -prefix[k]
        for i in range(1, n - 2 * k + 1):
            dp[0][i] = max(dp[0][i - 1], prefix[i + k] - prefix[i])

        dp[1][k] = -prefix[2 * k]
        for i in range(k, n - k + 1):
            dp[1][i] = max(dp[1][i - 1], dp[0][i - k] + prefix[i + k] - prefix[i])

        dp[2][2 * k] = -prefix[3 * k]
        for i in range(2 * k, n + 1):
            dp[2][i] = max(dp[2][i - 1], dp[1][i - 2 * k] + prefix[i] - prefix[i - k])

        res = []
        for i in range(2, -1, -1):
            for j in range(len(dp[i]) - 1, 0, -1):
                if dp[i][j] != dp[i][j - 1]:
                    res.append(j - k)
                    break

        return res[::-1]
