#https://leetcode.com/problems/diagonal-traverse-ii/
#Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.
# 
#Example 1:
#Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
#Output: [1,4,2,7,5,3,8,6,9]
#Example 2:
#Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
#Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i].length <= 105
#	1 <= sum(nums[i].length) <= 105
#	1 <= nums[i][j] <= 105
class Solution(object):
    def findDiagonalOrder(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        m = len(nums)
        n = sum(len(row) for row in nums)
        res = [0] * n
        idx = 0
        for i in range(m):
            for j in range(len(nums[i])):
                if (i+j) % 2 == 0:
                    res[idx] = nums[i][j]
                    idx += 1
        idx = n - 1
        for i in range(m):
            for j in range(len(nums[i])):
                if (i+j) % 2 == 1:
                    res[idx] = nums[i][j]
                    idx -= 1
        return res
