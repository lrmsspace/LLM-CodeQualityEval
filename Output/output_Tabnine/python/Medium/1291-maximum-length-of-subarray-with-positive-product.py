#https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
#Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.
#A subarray of an array is a consecutive sequence of zero or more values taken out of that array.
#Return the maximum length of a subarray with positive product.
# 
#Example 1:
#Input: nums = [1,-2,-3,4]
#Output: 4
#Explanation: The array nums already has a positive product of 24.
#Example 2:
#Input: nums = [0,1,-2,-3,-4]
#Output: 3
#Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
#Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
#Example 3:
#Input: nums = [-1,-2,-3,0,1]
#Output: 2
#Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].
# 
#Constraints:
#	1 <= nums.length <= 105
#	-109 <= nums[i] <= 109
class Solution(object):
    def getMaxLen(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Initialize variables
        max_len = 0
        left, right = 0, 0
        prod = 1
        
        # Iterate through the array
        while right < len(nums):
            # Update the product
            prod *= nums[right]
            
            # If the product is positive, update the maximum length
            while prod > 0:
                max_len = max(max_len, right - left + 1)
                prod /= nums[left]
                left += 1
            
            # Move to the next element
            right += 1
        
        return max_len
        