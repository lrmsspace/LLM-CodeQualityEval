#https://leetcode.com/problems/maximum-gap/
#Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
#You must write an algorithm that runs in linear time and uses linear extra space.
# 
#Example 1:
#Input: nums = [3,6,9,1]
#Output: 3
#Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
#Example 2:
#Input: nums = [10]
#Output: 0
#Explanation: The array contains less than 2 elements, therefore return 0.
# 
#Constraints:
#	1 <= nums.length <= 105
#	0 <= nums[i] <= 109
class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return 0
        
        a, b = min(nums), max(nums)
        size = math.ceil((b-a)/(len(nums)-1))
        bucket = [[None, None] for _ in range((b-a)//size + 1)]
        for n in nums:
            b = bucket[(n-a)//size]
            b[0] = n if b[0] is None else min(b[0], n)
            b[1] = n if b[1] is None else max(b[1], n)
        bucket = [b for b in bucket if b[0] is not None]
        return max(bucket[i][0]-bucket[i-1][1] for i in range(1, len(bucket)))
        
