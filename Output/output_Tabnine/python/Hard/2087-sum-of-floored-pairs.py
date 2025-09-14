#https://leetcode.com/problems/sum-of-floored-pairs/
#Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length in the array. Since the answer may be too large, return it modulo 109 + 7.
#The floor() function returns the integer part of the division.
# 
#Example 1:
#Input: nums = [2,5,9]
#Output: 10
#Explanation:
#floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
#floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
#floor(5 / 2) = 2
#floor(9 / 2) = 4
#floor(9 / 5) = 1
#We calculate the floor of the division for every pair of indices in the array then sum them up.
#Example 2:
#Input: nums = [7,7,7,7,7,7,7]
#Output: 49
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i] <= 105
class Solution(object):
    def sumOfFlooredPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        nums.sort()
        n = len(nums)
        count = [0] * n
        prefix_sum = [0] * n
        
        # Count the frequency of each number

        for i in range(n):
            count[nums[i]] += 1
        
        # Calculate the prefix sum of count
        for i in range(1, n):
            prefix_sum[i] = prefix_sum[i-1] + count[i]
        
        # Calculate the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length
        ans = 0
        for i in range(n):
            for j in range(i+1, n):
                diff = nums[j] - nums[i]
                # Calculate the floor of the division for each pair
                floor_div = (diff + nums[i] - 1) // nums[i]
                ans = (ans + (prefix_sum[j] - prefix_sum[i]) * floor_div) % MOD
        
        return ans
        