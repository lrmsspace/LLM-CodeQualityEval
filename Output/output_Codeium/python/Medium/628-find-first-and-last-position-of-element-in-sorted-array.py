#https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
#If target is not found in the array, return [-1, -1].
#You must write an algorithm with O(log n) runtime complexity.
# 
#Example 1:
#Input: nums = [5,7,7,8,8,10], target = 8
#Output: [3,4]
#Example 2:
#Input: nums = [5,7,7,8,8,10], target = 6
#Output: [-1,-1]
#Example 3:
#Input: nums = [], target = 0
#Output: [-1,-1]
# 
#Constraints:
#	0 <= nums.length <= 105
#	-109 <= nums[i] <= 109
#	nums is a non-decreasing array.
#	-109 <= target <= 109
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        start, end = -1, -1
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                start = mid
                r = mid - 1
            elif nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                end = mid
                l = mid + 1
            elif nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return [start, end]
