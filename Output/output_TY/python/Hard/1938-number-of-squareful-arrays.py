#https://leetcode.com/problems/number-of-squareful-arrays/
#An array is squareful if the sum of every pair of adjacent elements is a perfect square.
#Given an integer array nums, return the number of permutations of nums that are squareful.
#Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].
# 
#Example 1:
#Input: nums = [1,17,8]
#Output: 2
#Explanation: [1,8,17] and [17,8,1] are the valid permutations.
#Example 2:
#Input: nums = [2,2,2]
#Output: 1
# 
#Constraints:
#	1 <= nums.length <= 12
#	0 <= nums[i] <= 109
class Solution(object):
    def numSquarefulPerms(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        dp = [0] * (1 << n)
        dp[0] = 1
        for mask in range(1, 1 << n):
            for i in range(n):
                if mask & (1 << i) == 0:
                    continue
                for j in range(i + 1, n):
                    if mask & (1 << j) == 0:
                        continue
                    if int(sqrt(nums[i] + nums[j])) ** 2 == nums[i] + nums[j]:
                        dp[mask] += dp[mask ^ (1 << i) ^ (1 << j)]
        return dp[(1 << n) - 1]