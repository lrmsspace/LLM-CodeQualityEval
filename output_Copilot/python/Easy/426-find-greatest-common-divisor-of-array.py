#https://leetcode.com/problems/find-greatest-common-divisor-of-array/
#Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
#The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
# 
#Example 1:
#Input: nums = [2,5,6,9,10]
#Output: 2
#Explanation:
#The smallest number in nums is 2.
#The largest number in nums is 10.
#The greatest common divisor of 2 and 10 is 2.
#Example 2:
#Input: nums = [7,5,6,8,3]
#Output: 1
#Explanation:
#The smallest number in nums is 3.
#The largest number in nums is 8.
#The greatest common divisor of 3 and 8 is 1.
#Example 3:
#Input: nums = [3,3]
#Output: 3
#Explanation:
#The smallest number in nums is 3.
#The largest number in nums is 3.
#The greatest common divisor of 3 and 3 is 3.
# 
#Constraints:
#	2 <= nums.length <= 1000
#	1 <= nums[i] <= 1000
class Solution(object):
    def findGCD(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 计算最小值和最大值
        min_num = min(nums)
        max_num = max(nums)
        
        # 定义一个函数来计算最大公约数
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a
        
        # 返回最小值和最大值的最大公约数
        return gcd(min_num, max_num)        