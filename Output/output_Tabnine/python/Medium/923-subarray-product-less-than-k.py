#https://leetcode.com/problems/subarray-product-less-than-k/
#Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
# 
#Example 1:
#Input: nums = [10,5,2,6], k = 100
#Output: 8
#Explanation: The 8 subarrays that have product less than 100 are:
#[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
#Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
#Example 2:
#Input: nums = [1,2,3], k = 0
#Output: 0
# 
#Constraints:
#	1 <= nums.length <= 3 * 104
#	1 <= nums[i] <= 1000
#	0 <= k <= 106
class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k == 0:
            return 0
        
        left, right, product, count = 0, 0, 1, 0
        
        while right < len(nums):
            product *= nums[right]
            
            while product >= k:
                product /= nums[left]
                left += 1
            
            count += right - left + 1
            right += 1
        
        return count
        