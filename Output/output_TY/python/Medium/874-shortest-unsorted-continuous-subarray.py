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
        max_val = float('-inf')
        max_pos = -1
        min_val = float('inf')
        min_pos = -1
        for i in range(n):
            if nums[i] < max_val:
                max_pos = i
            else:
                max_val = nums[i]
            if nums[n - 1 - i] > min_val:
                min_pos = n - 1 - i
            else:
                min_val = nums[n - 1 - i]
        return max(0, max_pos - min_pos + 1)