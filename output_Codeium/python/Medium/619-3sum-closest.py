#https://leetcode.com/problems/3sum-closest/
#Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
#Return the sum of the three integers.
#You may assume that each input would have exactly one solution.
# 
#Example 1:
#Input: nums = [-1,2,1,-4], target = 1
#Output: 2
#Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
#Example 2:
#Input: nums = [0,0,0], target = 1
#Output: 0
#Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
# 
#Constraints:
#	3 <= nums.length <= 500
#	-1000 <= nums[i] <= 1000
#	-104 <= target <= 104
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        closest = float('inf')
        for i in range(len(nums)-2):
            l, r = i+1, len(nums)-1
            while l < r:
                curr_sum = nums[i]+nums[l]+nums[r]
                if curr_sum == target: return curr_sum
                if abs(curr_sum-target) < abs(closest-target): closest = curr_sum
                if curr_sum < target: l += 1
                else: r -= 1
        return closest
