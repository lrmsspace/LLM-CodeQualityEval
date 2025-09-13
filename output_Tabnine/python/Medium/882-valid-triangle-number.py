#https://leetcode.com/problems/valid-triangle-number/
#Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
# 
#Example 1:
#Input: nums = [2,2,3,4]
#Output: 3
#Explanation: Valid combinations are: 
#2,3,4 (using the first 2)
#2,3,4 (using the second 2)
#2,2,3
#Example 2:
#Input: nums = [4,2,3,4]
#Output: 4
# 
#Constraints:
#	1 <= nums.length <= 1000
#	0 <= nums[i] <= 1000
class Solution(object):
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Sort the array in ascending order
        nums.sort()
        
        # Initialize the count of valid triplets to 0
        count = 0
        
        # Iterate over the array from the third element to the end
        for i in range(2, len(nums)):
            # Initialize two pointers, one at the beginning and one at the end
            left = 0
            right = i - 1
            
            # While the left pointer is less than the right pointer
            while left < right:
                # Calculate the sum of the current triplet
                triplet_sum = nums[left] + nums[right] + nums[i]
                
                # If the sum is greater than or equal to the third element, decrement the right pointer
                if triplet_sum >= nums[i]:
                    right -= 1
                # If the sum is less than the third element, increment the left pointer
                else:
                    count += right - left
                    left += 1
        
        # Return the count of valid triplets
        return count
    