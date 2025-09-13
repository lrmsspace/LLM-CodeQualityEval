#https://leetcode.com/problems/largest-number/
#Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
#Since the result may be very large, so you need to return a string instead of an integer.
# 
#Example 1:
#Input: nums = [10,2]
#Output: "210"
#Example 2:
#Input: nums = [3,30,34,5,9]
#Output: "9534330"
# 
#Constraints:
#	1 <= nums.length <= 100
#	0 <= nums[i] <= 109
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        # Convert integers to strings and sort them based on their concatenation
        nums = [str(num) for num in nums]
        nums.sort(key=lambda x: x*3, reverse=True)
        
        # Remove leading zeros and join the strings to form the largest number
        return ''.join(num for num in nums if num!= '0') or '0'

        