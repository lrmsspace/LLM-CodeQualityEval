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
        self.ans = 0
        self.nums = nums
        self.n = len(nums)
        self.vis = [False]*self.n
        self.dfs([])
        return self.ans

    def dfs(self, perm):
        if len(perm) == self.n:
            self.ans += 1
            return 
        for i in range(self.n):
            if self.vis[i] or (perm and not self.isSquare(perm[-1], self.nums[i])):
                continue
            self.vis[i] = True
            self.dfs(perm + [self.nums[i]])
            self.vis[i] = False

    def isSquare(self, a, b):
        c = (a + b)**0.5
        return c == int(c)
