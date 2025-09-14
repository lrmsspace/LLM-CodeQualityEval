#https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
#Given an integer array nums and an integer k, modify the array in the following way:
#	choose an index i and replace nums[i] with -nums[i].
#You should apply this process exactly k times. You may choose the same index i multiple times.
#Return the largest possible sum of the array after modifying it in this way.
# 
#Example 1:
#Input: nums = [4,2,3], k = 1
#Output: 5
#Explanation: Choose index 1 and nums becomes [4,-2,3].
#Example 2:
#Input: nums = [3,-1,0,2], k = 3
#Output: 6
#Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].
#Example 3:
#Input: nums = [2,-3,-1,5,-4], k = 2
#Output: 13
#Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].
# 
#Constraints:
#	1 <= nums.length <= 104
#	-100 <= nums[i] <= 100
#	1 <= k <= 104
class Solution(object):
    def largestSumAfterKNegations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # Sort the array in ascending order
        nums.sort()
        
        # Iterate through the array and apply the negations
        for _ in range(k):
            # If the current element is positive, replace it with its negative
            if nums[0] >= 0:
                nums[0] = -nums[0]
            # If the current element is negative, replace it with the next positive element
            else:
                if len(nums) > 1 and nums[1] >= 0:
                    nums[1] = -nums[1]
                else:
                    nums[0] = -nums[0]
        
        # Return the sum of the array after applying the negations
        return sum(nums)
        