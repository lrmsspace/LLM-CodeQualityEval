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
        n = len(nums)
        if n < 2:
            return 0
        max_val = max(nums)
        min_val = min(nums)
        if max_val == min_val:
            return 0
        bucket_size = max(1, (max_val - min_val) // (n - 1))
        bucket_count = (max_val - min_val) // bucket_size + 1
        buckets_min = [float('inf')] * bucket_count
        buckets_max = [float('-inf')] * bucket_count
        for num in nums:
            index = (num - min_val) //bucket_size
            buckets_min[index] = min(buckets_min[index], num)
            buckets_max[index] = max(buckets_max[index], num)
        max_gap = float('-inf')
        pre_max = min_val
        for i in range(bucket_count):
            if buckets_min[i] == float('inf') and buckets_max[i] == float('-inf'):
                continue
            max_gap = max(max_gap, buckets_min[i] - pre_max)
            pre_max = buckets_max[i]
        return max(max_gap, max_val - pre_max)
