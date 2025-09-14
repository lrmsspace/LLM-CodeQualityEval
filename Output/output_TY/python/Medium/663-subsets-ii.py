#https://leetcode.com/problems/subsets-ii/
#Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
#The solution set must not contain duplicate subsets. Return the solution in any order.
# 
#Example 1:
#Input: nums = [1,2,2]
#Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
#Example 2:
#Input: nums = [0]
#Output: [[],[0]]
# 
#Constraints:
#	1 <= nums.length <= 10
#	-10 <= nums[i] <= 10
class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = [[]]
        for i in range(len(nums)):
            if i == 0 or nums[i] != nums[i-1]:
                temp = [x+[nums[i]] for x in res]
                res.extend(temp)
        return res