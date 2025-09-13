#https://leetcode.com/problems/move-zeroes/
#Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
#Note that you must do this in-place without making a copy of the array.
# 
#Example 1:
#Input: nums = [0,1,0,3,12]
#Output: [1,3,12,0,0]
#Example 2:
#Input: nums = [0]
#Output: [0]
# 
#Constraints:
#	1 <= nums.length <= 104
#	-231 <= nums[i] <= 231 - 1
# 
#Follow up: Could you minimize the total number of operations done?
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # Initialize a pointer to keep track of the position to place non-zero elements
        non_zero_index = 0
        
        # First pass: Move non-zero elements to the front of the array
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[non_zero_index] = nums[i]
                non_zero_index += 1
        
        # Second pass: Fill the remaining positions with zeros
        for i in range(non_zero_index, len(nums)):
            nums[i] = 0
#         return nums