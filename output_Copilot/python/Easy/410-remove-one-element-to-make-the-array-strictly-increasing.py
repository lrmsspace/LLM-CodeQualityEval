#https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
#Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise. If the array is already strictly increasing, return true.
#The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).
# 
#Example 1:
#Input: nums = [1,2,10,5,7]
#Output: true
#Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
#[1,2,5,7] is strictly increasing, so return true.
#Example 2:
#Input: nums = [2,3,1,2]
#Output: false
#Explanation:
#[3,1,2] is the result of removing the element at index 0.
#[2,1,2] is the result of removing the element at index 1.
#[2,3,2] is the result of removing the element at index 2.
#[2,3,1] is the result of removing the element at index 3.
#No resulting array is strictly increasing, so return false.
#Example 3:
#Input: nums = [1,1,1]
#Output: false
#Explanation: The result of removing any element is [1,1].
#[1,1] is not strictly increasing, so return false.
# 
#Constraints:
#	2 <= nums.length <= 1000
#	1 <= nums[i] <= 1000
class Solution(object):
    def canBeIncreasing(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # 统计不满足严格递增的元素对的个数
        count = 0
        for i in range(1, len(nums)):
            if nums[i] <= nums[i - 1]:
                count += 1
                # 如果已经有两个不满足的元素对，则返回 False
                if count > 1:
                    return False
                # 检查是否可以通过删除当前元素或前一个元素来解决问题
                if i > 1 and nums[i] <= nums[i - 2] and (i == len(nums) - 1 or nums[i + 1] <= nums[i - 1]):
                    return False
        return True        