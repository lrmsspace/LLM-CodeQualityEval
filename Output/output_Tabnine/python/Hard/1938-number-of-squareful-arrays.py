#https://leetcode.com/problems/number-of-squareful-arrays/
#An array is squareful if the sum of every pair of adjacent elements is a perfect square.
#Given an integer array nums, return the number of permutations of nums that are squareful.
#Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].
# 
#Example 1:
#Input: nums = [1,17,8]
#Output: 2
#Explanation: [1,8,17] and [17,8,1] are the valid permutations.
#Example 2:
#Input: nums = [2,2,2]
#Output: 1
# 
#Constraints:
#	1 <= nums.length <= 12
#	0 <= nums[i] <= 109
class Solution(object):
    def numSquarefulPerms(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        n = len(nums)
        memo = {}
        
        def dfs(start):
            if start == n:
                return 1
            if start in memo:
                return memo[start]
            
            count = 0
            for i in range(start, n):
                if i > start and nums[i] == nums[i-1]:
                    continue
                
                if nums[start] + nums[i] ** 0.5 == int(nums[start] + nums[i] ** 0.5):
                    count += dfs(start + 1)
            
            memo[start] = count
            return count
        
        return dfs(0)
        