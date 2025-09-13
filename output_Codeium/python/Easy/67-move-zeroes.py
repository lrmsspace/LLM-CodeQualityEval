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
        zero_position = 0  # Initialize the position to place the next non-zero element

        # Iterate through the list
        for i in range(len(nums)):
            # If the current element is not zero, swap it with the element at zero_position
            if nums[i] != 0:
                nums[i], nums[zero_position] = nums[zero_position], nums[i]
                zero_position += 1

        # Fill the remaining positions with zeros
        for i in range(zero_position, len(nums)):
            nums[i] = 0 

        return nums

