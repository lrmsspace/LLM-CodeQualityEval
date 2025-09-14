#https://leetcode.com/problems/maximum-average-subarray-i/
#You are given an integer array nums consisting of n elements, and an integer k.
#Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
# 
#Example 1:
#Input: nums = [1,12,-5,-6,50,3], k = 4
#Output: 12.75000
#Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
#Example 2:
#Input: nums = [5], k = 1
#Output: 5.00000
# 
#Constraints:
#	n == nums.length
#	1 <= k <= n <= 105
#	-104 <= nums[i] <= 104
class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        # Initialize the sum and the maximum average
        total_sum = sum(nums[:k])
        max_average = total_sum / k
        
        # Iterate over the rest of the array
        for i in range(k, len(nums)):
            # Update the total sum by subtracting the first element and adding the current element
            total_sum -= nums[i-k]
            total_sum += nums[i]
            
            # Update the maximum average if necessary
            max_average = max(max_average, total_sum / k)
        
        return max_average
        