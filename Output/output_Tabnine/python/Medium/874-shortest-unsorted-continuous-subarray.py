#https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
#Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
#Return the shortest such subarray and output its length.
# 
#Example 1:
#Input: nums = [2,6,4,8,10,9,15]
#Output: 5
#Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
#Example 2:
#Input: nums = [1,2,3,4]
#Output: 0
#Example 3:
#Input: nums = [1]
#Output: 0
# 
#Constraints:
#	1 <= nums.length <= 104
#	-105 <= nums[i] <= 105
# 
#Follow up: Can you solve it in O(n) time complexity?
class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Find the first element that violates the ascending order
        i = 0
        while i < len(nums) - 1 and nums[i] <= nums[i + 1]:
            i += 1
        
        # If the array is already sorted, return 0
        if i == len(nums) - 1:
            return 0
        
        # Find the last element that violates the ascending order
        j = len(nums) - 1
        while j > 0 and nums[j] >= nums[j - 1]:
            j -= 1
        
        # Find the first element in the sorted part that is larger than nums[i]
        k = i - 1
        while k >= 0 and nums[k] > nums[i]:
            k -= 1
        
        # Find the last element in the sorted part that is smaller than nums[j]
        l = j + 1
        while l < len(nums) and nums[l] < nums[j]:
            l += 1
        
        # Return the length of the subarray
        return l - k - 1
        