#https://leetcode.com/problems/closest-subsequence-sum/
#You are given an integer array nums and an integer goal.
#You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).
#Return the minimum possible value of abs(sum - goal).
#Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.
# 
#Example 1:
#Input: nums = [5,-7,3,5], goal = 6
#Output: 0
#Explanation: Choose the whole array as a subsequence, with a sum of 6.
#This is equal to the goal, so the absolute difference is 0.
#Example 2:
#Input: nums = [7,-9,15,-2], goal = -5
#Output: 1
#Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
#The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.
#Example 3:
#Input: nums = [1,2,3], goal = -7
#Output: 7
# 
#Constraints:
#	1 <= nums.length <= 40
#	-107 <= nums[i] <= 107
#	-109 <= goal <= 109
class Solution(object):
    def minAbsDifference(self, nums, goal):
        """
        :type nums: List[int]
        :type goal: int
        :rtype: int
        """
        def dfs(i, cur):
            if i == len(nums):
                sums.add(cur)
                return
            dfs(i + 1, cur + nums[i])
            dfs(i + 1, cur)
        sums = set()
        dfs(0, 0)
        sums = sorted(sums)
        res = float('inf')
        i = 0
        for s in sums:
            while i < len(sums) and s + sums[i] >= goal:
                i += 1
            if i < len(sums):
                res = min(res, abs(s + sums[i] - goal))
            if i > 0:
                res = min(res, abs(s + sums[i - 1] - goal))
        return res
        