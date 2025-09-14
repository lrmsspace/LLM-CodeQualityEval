#https://leetcode.com/problems/permutations/
#Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
# 
#Example 1:
#Input: nums = [1,2,3]
#Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
#Example 2:
#Input: nums = [0,1]
#Output: [[0,1],[1,0]]
#Example 3:
#Input: nums = [1]
#Output: [[1]]
# 
#Constraints:
#	1 <= nums.length <= 6
#	-10 <= nums[i] <= 10
#	All the integers of nums are unique.
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        self.dfs(nums, [], result)
        return result

    def dfs(self, nums, path, result):
        if len(nums) == 0:
            result.append(path)
        else:
            for i in range(len(nums)):
                self.dfs(nums[:i] + nums[i+1:], path + [nums[i]], result)
