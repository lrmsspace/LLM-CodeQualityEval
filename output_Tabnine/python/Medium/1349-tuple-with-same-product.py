#https://leetcode.com/problems/tuple-with-same-product/
#Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.
# 
#Example 1:
#Input: nums = [2,3,4,6]
#Output: 8
#Explanation: There are 8 valid tuples:
#(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
#(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
#Example 2:
#Input: nums = [1,2,4,5,10]
#Output: 16
#Explanation: There are 16 valid tuples:
#(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
#(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
#(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
#(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
# 
#Constraints:
#	1 <= nums.length <= 1000
#	1 <= nums[i] <= 104
#	All elements in nums are distinct.
class Solution(object):
    def tupleSameProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        n = len(nums)
        res = 0
        
        for i in range(n-3):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            for j in range(i+1, n-2):
                if j > i+1 and nums[j] == nums[j-1]:
                    continue
                left, right = j+1, n-1
                while left < right:
                    product = nums[i] * nums[j] * nums[left] * nums[right]
                    if product == nums[i] * nums[j] * nums[left] * nums[right]:
                        res += 1
                        left += 1
                        right -= 1
                    elif product < nums[i] * nums[j] * nums[left] * nums[right]:
                        left += 1
                    else:
                        right -= 1
        
        return res
        