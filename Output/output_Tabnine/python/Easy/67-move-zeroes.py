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
        # Initialize two pointers, one for the first non-zero element and one for the current position to be filled
        i, j = 0, 0
        
        # Iterate through the array
        while j < len(nums):
            # If the current element is non-zero, swap it with the element at the first non-zero position
            if nums[j]!= 0:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
            j += 1
        # Fill the remaining positions with zeros
        for k in range(i, len(nums)):
            nums[k] = 0
        return nums
        