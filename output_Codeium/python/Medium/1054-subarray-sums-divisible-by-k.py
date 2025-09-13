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
        count = {0: 1}
        prefix_sum = 0
        ans = 0
        for num in nums:
            prefix_sum += num
            if prefix_sum % k in count:
                ans += count[prefix_sum % k]
            count.setdefault(prefix_sum % k, 0)
            count[prefix_sum % k] += 1
        return ans
