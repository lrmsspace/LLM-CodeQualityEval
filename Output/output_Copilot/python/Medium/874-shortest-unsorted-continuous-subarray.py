#https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
#Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
#Return the shortest such subarray and output its length.
# 
#Example 1:
#Input: nums = [2,6,4,8,10,9,15]
#Output: 5
#Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
#Example 2:
#Input: nums = [1,2,3,4]
#Output: 0
#Example 3:
#Input: nums = [1]
#Output: 0
# 
#Constraints:
#	1 <= nums.length <= 104
#	-105 <= nums[i] <= 105
# 
#Follow up: Can you solve it in O(n) time complexity?
class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 1. 找到数组的最小值和最大值
        min_val = float('inf')
        max_val = float('-inf')
        for i in range(len(nums)):
            if nums[i] < min_val:
                min_val = nums[i]
            if nums[i] > max_val:
                max_val = nums[i]

        # 2. 找到最小值和最大值在原数组中的位置
        left, right = 0, len(nums) - 1
        while left < len(nums) and nums[left] <= min_val:
            left += 1
        while right >= 0 and nums[right] >= max_val:
            right -= 1

        # 3. 返回子数组的长度
        return right - left + 1 if right - left + 1 > 0 else 0        