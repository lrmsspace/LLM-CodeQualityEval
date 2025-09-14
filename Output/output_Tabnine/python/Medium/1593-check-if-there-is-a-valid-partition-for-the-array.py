#https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/
#You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.
#We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:
#	The subarray consists of exactly 2, equal elements. For example, the subarray [2,2] is good.
#	The subarray consists of exactly 3, equal elements. For example, the subarray [4,4,4] is good.
#	The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
#Return true if the array has at least one valid partition. Otherwise, return false.
# 
#Example 1:
#Input: nums = [4,4,4,5,6]
#Output: true
#Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
#This partition is valid, so we return true.
#Example 2:
#Input: nums = [1,1,1,2]
#Output: false
#Explanation: There is no valid partition for this array.
# 
#Constraints:
#	2 <= nums.length <= 105
#	1 <= nums[i] <= 106
class Solution(object):
    def validPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # If the array has less than 3 elements, it's not possible to form a valid partition
        if len(nums) < 3:
            return False
        
        # Initialize a list to store the counts of each consecutive difference
        diff_counts = [0] * 1000001
        
        # Count the occurrences of each consecutive difference
        for i in range(1, len(nums)):
            diff = nums[i] - nums[i-1]
            diff_counts[diff] += 1
        
        # Check if the counts of consecutive differences meet the conditions for a valid partition
        for diff, count in diff_counts.items():
            if diff == 0 and count >= 2:
                continue
            if diff == 1 and count >= 3:
                continue
            return False
        
        return True
        