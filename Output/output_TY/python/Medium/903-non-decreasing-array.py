#https://leetcode.com/problems/non-decreasing-array/
#Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.
#We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
# 
#Example 1:
#Input: nums = [4,2,3]
#Output: true
#Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
#Example 2:
#Input: nums = [4,2,1]
#Output: false
#Explanation: You cannot get a non-decreasing array by modifying at most one element.
# 
#Constraints:
#	n == nums.length
#	1 <= n <= 104
#	-105 <= nums[i] <= 105
class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        if n <= 2: return True
        for i in range(n-1):
            if nums[i] <= nums[i+1]: continue
            else:
                if i == 0 or nums[i-1] <= nums[i+1]: nums[i] = nums[i+1]
                elif i == n-2 or nums[i] <= nums[i+2]: nums[i+1] = nums[i]
                else: return False
        return True