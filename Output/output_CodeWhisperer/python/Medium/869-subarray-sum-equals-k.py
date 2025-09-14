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
        sum = 0
        d = {0: 1}
        for i in range(len(nums)):
            sum += nums[i]
            if sum - k in d:
                count += d[sum - k]
            if sum in d:
                d[sum] += 1
            else:
                d[sum] = 1
        return count

        