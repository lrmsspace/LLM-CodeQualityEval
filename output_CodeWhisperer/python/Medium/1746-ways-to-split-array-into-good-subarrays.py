#https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/
#You are given a binary array nums.
#A subarray of an array is good if it contains exactly one element with the value 1.
#Return an integer denoting the number of ways to split the array nums into good subarrays. As the number may be too large, return it modulo 109 + 7.
#A subarray is a contiguous non-empty sequence of elements within an array.
# 
#Example 1:
#Input: nums = [0,1,0,0,1]
#Output: 3
#Explanation: There are 3 ways to split nums into good subarrays:
#- [0,1] [0,0,1]
#- [0,1,0] [0,1]
#- [0,1,0,0] [1]
#Example 2:
#Input: nums = [0,1,0]
#Output: 1
#Explanation: There is 1 way to split nums into good subarrays:
#- [0,1,0]
# 
#Constraints:
#	1 <= nums.length <= 105
#	0 <= nums[i] <= 1
class Solution(object):
    def numberOfGoodSubarraySplits(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        
        # If there's no 1 in the array, return 0
        if 1 not in nums:
            return 0
            
        # Find positions of all 1s
        one_positions = []
        for i, num in enumerate(nums):
            if num == 1:
                one_positions.append(i)
        
        # If there's only one 1, return 1
        if len(one_positions) == 1:
            return 1
            
        # Calculate ways to split between consecutive 1s
        result = 1
        for i in range(1, len(one_positions)):
            # Number of zeros between consecutive 1s plus 1
            ways = one_positions[i] - one_positions[i-1]
            result = (result * ways) % MOD
            
        return result
    