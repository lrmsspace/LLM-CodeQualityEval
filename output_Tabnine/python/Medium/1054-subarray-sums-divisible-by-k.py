#https://leetcode.com/problems/subarray-sums-divisible-by-k/
#Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
#A subarray is a contiguous part of an array.
# 
#Example 1:
#Input: nums = [4,5,0,-2,-3,1], k = 5
#Output: 7
#Explanation: There are 7 subarrays with a sum divisible by k = 5:
#[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
#Example 2:
#Input: nums = [5], k = 9
#Output: 0
# 
#Constraints:
#	1 <= nums.length <= 3 * 104
#	-104 <= nums[i] <= 104
#	2 <= k <= 104
class Solution(object):
    def subarraysDivByK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # Initialize a prefix sum list and a dictionary to store the count of each prefix sum modulo k
        prefix_sum = [0] * (len(nums) + 1)
        count = {0: 1}
        
        # Calculate prefix sums and update the count dictionary
        for i, num in enumerate(nums):
            prefix_sum[i + 1] = (prefix_sum[i] + num) % k
            count[prefix_sum[i + 1]] = count.get(prefix_sum[i + 1], 0) + 1
        
        # Count the subarrays with a sum divisible by k
        result = 0
        for count in count.values():
            result += count * (count - 1) // 2
        
        return result
        