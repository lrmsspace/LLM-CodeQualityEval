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
        if not nums:
            return [-1, -1]

        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                # 找到目标值，接下来找到范围
                start, end = mid, mid
                while start > 0 and nums[start - 1] == target:
                    start -= 1
                while end < len(nums) - 1 and nums[end + 1] == target:
                    end += 1
                return [start, end]

        return [-1, -1]        