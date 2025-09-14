#https://leetcode.com/problems/maximum-product-subarray/
#Given an integer array nums, find a subarray that has the largest product, and return the product.
#The test cases are generated so that the answer will fit in a 32-bit integer.
# 
#Example 1:
#Input: nums = [2,3,-2,4]
#Output: 6
#Explanation: [2,3] has the largest product 6.
#Example 2:
#Input: nums = [-2,0,-1]
#Output: 0
#Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
# 
#Constraints:
#	1 <= nums.length <= 2 * 104
#	-10 <= nums[i] <= 10
#	The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Initialize variables to store the maximum and minimum product ending at each index
        max_ending_here = nums[0]
        min_ending_here = nums[0]
        max_so_far = nums[0]
        
        # Iterate through the array
        for i in range(1, len(nums)):
            # Calculate the new maximum and minimum product ending at the current index
            temp = max_ending_here
            max_ending_here = max(nums[i], nums[i] * max_ending_here, nums[i] * min_ending_here)
            min_ending_here = min(nums[i], nums[i] * temp, nums[i] * min_ending_here)
            
            # Update the maximum product so far
            max_so_far = max(max_so_far, max_ending_here)
        
        return max_so_far
        