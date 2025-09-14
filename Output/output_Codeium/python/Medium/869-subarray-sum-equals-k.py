#https://leetcode.com/problems/subarray-sum-equals-k/
#Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
#A subarray is a contiguous non-empty sequence of elements within an array.
# 
#Example 1:
#Input: nums = [1,1,1], k = 2
#Output: 2
#Example 2:
#Input: nums = [1,2,3], k = 3
#Output: 2
# 
#Constraints:
#	1 <= nums.length <= 2 * 104
#	-1000 <= nums[i] <= 1000
#	-107 <= k <= 107
class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        count = 0
        cum_sum = 0
        sum_dict = {0:1}
        for num in nums:
            cum_sum += num
            if cum_sum - k in sum_dict:
                count += sum_dict[cum_sum - k]
            if cum_sum not in sum_dict:
                sum_dict[cum_sum] = 0
            sum_dict[cum_sum] += 1
        return count
