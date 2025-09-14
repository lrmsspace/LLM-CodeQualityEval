#https://leetcode.com/problems/contains-duplicate-iii/
#You are given an integer array nums and two integers indexDiff and valueDiff.
#Find a pair of indices (i, j) such that:
#	i != j,
#	abs(i - j) <= indexDiff.
#	abs(nums[i] - nums[j]) <= valueDiff, and
#Return true if such pair exists or false otherwise.
# 
#Example 1:
#Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
#Output: true
#Explanation: We can choose (i, j) = (0, 3).
#We satisfy the three conditions:
#i != j --> 0 != 3
#abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
#abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
#Example 2:
#Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
#Output: false
#Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false.
# 
#Constraints:
#	2 <= nums.length <= 105
#	-109 <= nums[i] <= 109
#	1 <= indexDiff <= nums.length
#	0 <= valueDiff <= 109
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, indexDiff, valueDiff):
        """
        :type nums: List[int]
        :type indexDiff: int
        :type valueDiff: int
        :rtype: bool
        """
        # Create a set to store the last seen values at indices
        seen = set()
        
        # Iterate over the array
        for i, num in enumerate(nums):
            # Check if the absolute difference between the current value and the last seen value is within the allowed range
            # If it is, return True
            if valueDiff >= 0 and abs(num - seen.get(num, float('-inf'))) <= valueDiff:
                return True
            
            # If the absolute difference between the current value and the last seen value exceeds the allowed range,
            # remove the last seen value from the set and add the current value to the set
            if valueDiff < 0 and (
                seen.get(num + valueDiff) is not None or
                seen.get(num - valueDiff) is not None
            ):
                seen.remove(num + valueDiff if seen.get(num + valueDiff) is not None else num - valueDiff)
                seen.add(num)

        # If no pair is found within the allowed range, return False
        return False
        