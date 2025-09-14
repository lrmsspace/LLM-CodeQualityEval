#https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
#You are given an integer array nums and two integers minK and maxK.
#A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
#	The minimum value in the subarray is equal to minK.
#	The maximum value in the subarray is equal to maxK.
#Return the number of fixed-bound subarrays.
#A subarray is a contiguous part of an array.
# 
#Example 1:
#Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
#Output: 2
#Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
#Example 2:
#Input: nums = [1,1,1,1], minK = 1, maxK = 1
#Output: 10
#Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
# 
#Constraints:
#	2 <= nums.length <= 105
#	1 <= nums[i], minK, maxK <= 106
class Solution(object):
    def countSubarrays(self, nums, minK, maxK):
        """
        :type nums: List[int]
        :type minK: int
        :type maxK: int
        :rtype: int
        """
        # Initialize count of subarrays and prefix sum array
        count = 0
        prefix_sum = [0] * (len(nums) + 1)
        
        # Iterate through the array and update prefix sum array
        for i in range(len(nums)):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]
        
        # Iterate through prefix sum array to find fixed-bound subarrays
        for i in range(len(prefix_sum)):
            # Find the minimum value in the subarray
            min_value = min(prefix_sum[i+1:] - prefix_sum[i:i+minK])
            
            # Find the maximum value in the subarray
            max_value = max(prefix_sum[i+1:] - prefix_sum[i:i+maxK])
            
            # Check if the minimum and maximum values are equal to minK and maxK respectively
            if min_value == minK and max_value == maxK:
                count += 1
        
        return count