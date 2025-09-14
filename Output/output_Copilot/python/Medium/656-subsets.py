#https://leetcode.com/problems/subsets/
#Given an integer array nums of unique elements, return all possible subsets (the power set).
#The solution set must not contain duplicate subsets. Return the solution in any order.
# 
#Example 1:
#Input: nums = [1,2,3]
#Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
#Example 2:
#Input: nums = [0]
#Output: [[],[0]]
# 
#Constraints:
#	1 <= nums.length <= 10
#	-10 <= nums[i] <= 10
#	All the numbers of nums are unique.
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        n = len(nums)
        # 2^n possible subsets
        for i in range(1 << n):
            subset = []
            for j in range(n):
                # Check if the j-th bit is set in i
                if i & (1 << j):
                    subset.append(nums[j])
            result.append(subset)
        return result        