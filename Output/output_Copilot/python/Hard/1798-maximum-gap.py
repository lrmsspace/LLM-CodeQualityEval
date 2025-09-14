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

        max_num = max(nums)
        min_num = min(nums)

        if max_num == min_num:
            return 0

        bucket_size = max(1, (max_num - min_num) // (len(nums) - 1))
        bucket_count = (max_num - min_num) // bucket_size + 1

        buckets = [[float('inf'), float('-inf')] for _ in range(bucket_count)]

        for num in nums:
            bucket_index = (num - min_num) // bucket_size
            buckets[bucket_index][0] = min(buckets[bucket_index][0], num)
            buckets[bucket_index][1] = max(buckets[bucket_index][1], num)

        max_gap = 0
        previous_max = min_num

        for i in range(bucket_count):
            if buckets[i][0] == float('inf'):
                continue
            max_gap = max(max_gap, buckets[i][0] - previous_max)
            previous_max = buckets[i][1]

        return max_gap        