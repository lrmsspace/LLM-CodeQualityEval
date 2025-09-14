#https://leetcode.com/problems/count-the-number-of-good-subarrays/
#Given an integer array nums and an integer k, return the number of good subarrays of nums.
#A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
#A subarray is a contiguous non-empty sequence of elements within an array.
# 
#Example 1:
#Input: nums = [1,1,1,1,1], k = 10
#Output: 1
#Explanation: The only good subarray is the array nums itself.
#Example 2:
#Input: nums = [3,1,4,3,2,2,4], k = 2
#Output: 4
#Explanation: There are 4 different good subarrays:
#- [3,1,4,3,2,2] that has 2 pairs.
#- [3,1,4,3,2,2,4] that has 3 pairs.
#- [1,4,3,2,2,4] that has 2 pairs.
#- [4,3,2,2,4] that has 2 pairs.
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i], k <= 109
class Solution(object):
    def countGood(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # Initialize the count of good subarrays
        count = 0
        
        # Create a prefix sum array
        prefix_sum = [0] * (len(nums) + 1)
        for i in range(len(nums)):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]
        
        # Iterate through the prefix sum array
        for i in range(len(prefix_sum) - k + 1):
            for j in range(i + k, len(prefix_sum) + 1):
                # Check if the current subarray has exactly k pairs of indices (i, j)
                if self.has_k_pairs(prefix_sum, i, j):
                    count += 1
        
        return count
        