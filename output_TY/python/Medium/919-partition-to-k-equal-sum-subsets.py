#https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
#Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
# 
#Example 1:
#Input: nums = [4,3,2,3,5,2,1], k = 4
#Output: true
#Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
#Example 2:
#Input: nums = [1,2,3,4], k = 3
#Output: false
# 
#Constraints:
#	1 <= k <= nums.length <= 16
#	1 <= nums[i] <= 104
#	The frequency of each element is in the range [1, 4].
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        sum_nums = sum(nums)
        if sum_nums % k != 0:
            return False
        target = sum_nums // k
        nums.sort()
        if nums[-1] > target:
            return False
        n = len(nums)
        dp = [False] * (1 << n)
        dp[0] = True
        for i in range(1, 1 << n):
            for j in range(n):
                if i & (1 << j) == 0:
                    continue
                pre = i - (1 << j)
                if dp[pre] and nums[j] <= target -(sum(dp[pre]) % target):
                    dp[i] = True
                    break
        return dp[(1 << n) - 1]