#https://leetcode.com/problems/count-the-number-of-fair-pairs/
#Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
#A pair (i, j) is fair if:
#	0 <= i < j < n, and
#	lower <= nums[i] + nums[j] <= upper
# 
#Example 1:
#Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
#Output: 6
#Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
#Example 2:
#Input: nums = [1,7,9,2,5], lower = 11, upper = 11
#Output: 1
#Explanation: There is a single fair pair: (2,3).
# 
#Constraints:
#	1 <= nums.length <= 105
#	nums.length == n
#	-109 <= nums[i] <= 109
#	-109 <= lower <= upper <= 109
class Solution(object):
    def countFairPairs(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        nums.sort()
        count = 0
        n = len(nums)
        
        def countPairsLessThan(target):
            left = 0
            right = n - 1
            total = 0
            
            while left < right:
                if nums[left] + nums[right] < target:
                    total += right - left
                    left += 1
                else:
                    right -= 1
            
            return total
        
        return countPairsLessThan(upper + 1) - countPairsLessThan(lower)

