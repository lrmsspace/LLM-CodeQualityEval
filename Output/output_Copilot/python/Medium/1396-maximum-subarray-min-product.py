#https://leetcode.com/problems/maximum-subarray-min-product/
#The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.
#	For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
#Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. Since the answer may be large, return it modulo 109 + 7.
#Note that the min-product should be maximized before performing the modulo operation. Testcases are generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.
#A subarray is a contiguous part of an array.
# 
#Example 1:
#Input: nums = [1,2,3,2]
#Output: 14
#Explanation: The maximum min-product is achieved with the subarray [2,3,2] (minimum value is 2).
#2 * (2+3+2) = 2 * 7 = 14.
#Example 2:
#Input: nums = [2,3,3,1,2]
#Output: 18
#Explanation: The maximum min-product is achieved with the subarray [3,3] (minimum value is 3).
#3 * (3+3) = 3 * 6 = 18.
#Example 3:
#Input: nums = [3,1,5,6,4,2]
#Output: 60
#Explanation: The maximum min-product is achieved with the subarray [5,6,4] (minimum value is 4).
#4 * (5+6+4) = 4 * 15 = 60.
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i] <= 107
class Solution(object):
    def maxSumMinProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        left = [0] * n
        right = [0] * n
        stack = []
        
        # Calculate left boundaries for each element
        for i in range(n):
            while stack and nums[stack[-1]] >= nums[i]:
                stack.pop()
            left[i] = stack[-1] if stack else -1
            stack.append(i)
        
        stack.clear()
        
        # Calculate right boundaries for each element
        for i in range(n - 1, -1, -1):
            while stack and nums[stack[-1]] > nums[i]:
                stack.pop()
            right[i] = stack[-1] if stack else n
            stack.append(i)
        
        max_product = 0
        
        # Calculate the maximum min-product using the boundaries
        for i in range(n):
            product = nums[i] * (sum(nums[left[i] + 1:right[i]]) % (10**9 + 7))
            max_product = max(max_product, product)
        
        return max_product % (10**9 + 7)        