#https://leetcode.com/problems/valid-triangle-number/
#Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
# 
#Example 1:
#Input: nums = [2,2,3,4]
#Output: 3
#Explanation: Valid combinations are: 
#2,3,4 (using the first 2)
#2,3,4 (using the second 2)
#2,2,3
#Example 2:
#Input: nums = [4,2,3,4]
#Output: 4
# 
#Constraints:
#	1 <= nums.length <= 1000
#	0 <= nums[i] <= 1000
class Solution(object):
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        n = len(nums)
        ans = 0
        for i in range(n):
            k = i
            for j in range(i+1, n):
                while k+1 < n and nums[k+1] < nums[i] + nums[j]:
                    k += 1
                ans += max(k - j, 0)
        return ans