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
        n = len(nums)
        if n < 2:
            return 0
        
        left, right = -1, -1
        max_seen, min_seen = nums[0], nums[-1]
        
        # Find the first element from the left that is out of order
        for i in range(1, n):
            if nums[i] < max_seen:
                right = i
            else:
                max_seen = nums[i]
        
        # Find the first element from the right that is out of order
        for i in range(n - 2, -1, -1):
            if nums[i] > min_seen:
                left = i
            else:
                min_seen = nums[i]
        
        # If no out-of-order elements found, the array is already sorted
        if left == -1:
            return 0
        
        return right - left + 1
        