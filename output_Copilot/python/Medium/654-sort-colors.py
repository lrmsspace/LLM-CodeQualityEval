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
        # Initialize pointers for the current position, and the boundaries for red and blue
        current = 0
        red_boundary = 0
        blue_boundary = len(nums) - 1

        # Iterate until the current position exceeds the blue boundary
        while current <= blue_boundary:
            # If the current color is red (0), swap it with the red boundary and move both pointers forward
            if nums[current] == 0:
                nums[current], nums[red_boundary] = nums[red_boundary], nums[current]
                red_boundary += 1
                current += 1
            # If the current color is white (1), just move the current pointer forward
            elif nums[current] == 1:
                current += 1
            # If the current color is blue (2), swap it with the blue boundary and move the blue boundary backward
            else:
                nums[current], nums[blue_boundary] = nums[blue_boundary], nums[current]
                blue_boundary -= 1  
                    # Do not move the current pointer forward in this case, as the swapped element needs to be checked  