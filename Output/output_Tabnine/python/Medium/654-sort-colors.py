#https://leetcode.com/problems/sort-colors/
#Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
#We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
#You must solve this problem without using the library's sort function.
# 
#Example 1:
#Input: nums = [2,0,2,1,1,0]
#Output: [0,0,1,1,2,2]
#Example 2:
#Input: nums = [2,0,1]
#Output: [0,1,2]
# 
#Constraints:
#	n == nums.length
#	1 <= n <= 300
#	nums[i] is either 0, 1, or 2.
# 
#Follow up: Could you come up with a one-pass algorithm using only constant extra space?
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # Initialize pointers for the three colors
        left, mid, right = 0, 0, len(nums) - 1
        
        # Traverse the array
        while mid <= right:
            # If the current element is 0, swap it with the element at the left pointer
            if nums[mid] == 0:
                nums[left], nums[mid] = nums[mid], nums[left]
                left += 1
                mid += 1
            # If the current element is 1, move to the next element
            elif nums[mid] == 1:
                mid += 1
            # If the current element is 2, swap it with the element at the right pointer
            else:
                nums[mid], nums[right] = nums[right], nums[mid]
                right -= 1
        return nums
        