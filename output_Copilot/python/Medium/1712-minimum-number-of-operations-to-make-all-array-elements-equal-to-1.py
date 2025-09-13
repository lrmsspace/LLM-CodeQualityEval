#https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/
#You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:
#	Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
#Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.
#The gcd of two integers is the greatest common divisor of the two integers.
# 
#Example 1:
#Input: nums = [2,6,3,4]
#Output: 4
#Explanation: We can do the following operations:
#- Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
#- Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
#- Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
#- Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
#Example 2:
#Input: nums = [2,10,6,14]
#Output: -1
#Explanation: It can be shown that it is impossible to make all the elements equal to 1.
# 
#Constraints:
#	2 <= nums.length <= 50
#	1 <= nums[i] <= 106
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from math import gcd
        from functools import reduce
        
        # Check if the GCD of the entire array is 1
        overall_gcd = reduce(gcd, nums)
        if overall_gcd != 1:
            return -1
        
        # Find the first and last occurrence of 1 in the array
        first_one = -1
        last_one = -1
        
        for i in range(len(nums)):
            if nums[i] == 1:
                if first_one == -1:
                    first_one = i
                last_one = i
        
        # If there is no 1 in the array, return -1 (this case is already handled above)
        if first_one == -1:
            return -1
        
        # Calculate the minimum number of operations needed to make all elements equal to 1
        return min(last_one + 1, len(nums) - first_one) + len(nums) - 2        