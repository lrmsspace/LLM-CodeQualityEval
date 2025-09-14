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
        mod = 10**9 + 7
        max_num = max(nums)
        count = [0] * (max_num + 1)
        for num in nums:
            count[num] += 1
        prefix_sum = [0] * (max_num + 1)
        for i in range(1, max_num + 1):
            prefix_sum[i] = prefix_sum[i - 1] + count[i]
        result = 0
        for i in range(1, max_num + 1):
            if count[i] == 0:
                continue
            j = i
            while j <= max_num:
                result += count[i] * (prefix_sum[min(max_num, (j + i - 1))] - prefix_sum[j - 1]) * (j // i)
                result %= mod
                j += i
        return result
        