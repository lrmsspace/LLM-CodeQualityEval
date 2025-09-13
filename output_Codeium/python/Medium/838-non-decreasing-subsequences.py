#https://leetcode.com/problems/non-decreasing-subsequences/
#Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
# 
#Example 1:
#Input: nums = [4,6,7,7]
#Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
#Example 2:
#Input: nums = [4,4,3,2,1]
#Output: [[4,4]]
# 
#Constraints:
#	1 <= nums.length <= 15
#	-100 <= nums[i] <= 100
class Solution(object):
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        def backtrack(start, path):
            if len(path) > 1:
                res.append(path[:])
            seen = set()
            for i in range(start, len(nums)):
                if path and nums[i] < path[-1] or nums[i] in seen:
                    continue
                seen.add(nums[i])
                path.append(nums[i])
                backtrack(i + 1, path)
                path.pop()
        backtrack(0, [])
        return res
