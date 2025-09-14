#https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
#Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
#Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
# 
#Example 1:
#Input: nums = [1,2,1,2,6,7,5,1], k = 2
#Output: [0,3,5]
#Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
#We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
#Example 2:
#Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
#Output: [0,2,4]
# 
#Constraints:
#	1 <= nums.length <= 2 * 104
#	1 <= nums[i] < 216
#	1 <= k <= floor(nums.length / 3)
class Solution(object):
    def maxSumOfThreeSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        n = len(nums)
        prefix_sum = [0] * (n + 1)
        for i in range(n):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]
        
        # Compute the sum of the first k elements
        max_sum = float('-inf')
        max_indices = []
        for i in range(n - k + 1):
            cur_sum = prefix_sum[i + k] - prefix_sum[i]
            if cur_sum > max_sum:
                max_sum = cur_sum
                max_indices = [i]
            elif cur_sum == max_sum:
                max_indices.append(i)
        
        # Compute the sum of the second k elements
        max_sum = float('-inf')
        max_indices2 = []
        for i in range(n - 2 * k + 1):
            cur_sum = prefix_sum[i + 2 * k] - prefix_sum[i + k]
            if cur_sum > max_sum:
                max_sum = cur_sum
                max_indices2 = [i + k]
            elif cur_sum == max_sum:
                max_indices2.append(i + k)
        
        # Find the maximum sum of the three subarrays
        max_sum = float('-inf')
        result = []
        for i in range(n - 3 * k + 1):
            cur_sum = prefix_sum[i + 3 * k] - prefix_sum[i]
            if cur_sum > max_sum:
                max_sum = cur_sum
                result = [max_indices[i // k], max_indices2[i // (2 * k)], i]
        
        return result
        