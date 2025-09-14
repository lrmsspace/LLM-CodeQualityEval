#https://leetcode.com/problems/sum-of-beauty-in-the-array/
#You are given a 0-indexed integer array nums. For each index i (1 <= i <= nums.length - 2) the beauty of nums[i] equals:
#	2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k <= nums.length - 1.
#	1, if nums[i - 1] < nums[i] < nums[i + 1], and the previous condition is not satisfied.
#	0, if none of the previous conditions holds.
#Return the sum of beauty of all nums[i] where 1 <= i <= nums.length - 2.
# 
#Example 1:
#Input: nums = [1,2,3]
#Output: 2
#Explanation: For each index i in the range 1 <= i <= 1:
#- The beauty of nums[1] equals 2.
#Example 2:
#Input: nums = [2,4,6,4]
#Output: 1
#Explanation: For each index i in the range 1 <= i <= 2:
#- The beauty of nums[1] equals 1.
#- The beauty of nums[2] equals 0.
#Example 3:
#Input: nums = [3,2,1]
#Output: 0
#Explanation: For each index i in the range 1 <= i <= 1:
#- The beauty of nums[1] equals 0.
# 
#Constraints:
#	3 <= nums.length <= 105
#	1 <= nums[i] <= 105
class Solution(object):
    def sumOfBeauties(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        left_min = [0] * n
        right_max = [0] * n
        
        left_min[0] = nums[0]
        for i in range(1, n):
            left_min[i] = min(left_min[i-1], nums[i])
        
        right_max[n-1] = nums[n-1]
        for i in range(n-2, -1, -1):
            right_max[i] = max(right_max[i+1], nums[i])
        
        beauty = 0
        for i in range(1, n-1):
            if nums[i] > left_min[i-1] and nums[i] < right_max[i+1]:
                beauty += 2
            elif nums[i] > left_min[i-1]:
                beauty += 1
        
        return beauty
        