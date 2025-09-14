#https://leetcode.com/problems/permutations-ii/
#Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
# 
#Example 1:
#Input: nums = [1,1,2]
#Output:
#[[1,1,2],
# [1,2,1],
# [2,1,1]]
#Example 2:
#Input: nums = [1,2,3]
#Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
# 
#Constraints:
#	1 <= nums.length <= 8
#	-10 <= nums[i] <= 10
class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def backtrack(start, end):
            if start == end:
                res.append(nums[:])
            for i in range(start, end):
                if nums[i]!= nums[start]:
                    nums[start], nums[i] = nums[i], nums[start]
                    backtrack(start+1, end)
                    nums[start], nums[i] = nums[i], nums[start]
        
        nums.sort()
        res = []
        backtrack(0, len(nums))
        return res
        