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
        if indexDiff <= 0 or valueDiff < 0:
            return False

        # Create a dictionary to store the buckets
        buckets = {}
        bucket_size = valueDiff + 1

        for i in range(len(nums)):
            # Calculate the bucket index for the current number
            bucket_index = nums[i] // bucket_size

            # Check if the current bucket already exists
            if bucket_index in buckets:
                return True

            # Check the neighboring buckets
            if (bucket_index - 1 in buckets and abs(nums[i] - buckets[bucket_index - 1]) <= valueDiff) or \
               (bucket_index + 1 in buckets and abs(nums[i] - buckets[bucket_index + 1]) <= valueDiff):
                return True

            # Add the current number to the appropriate bucket
            buckets[bucket_index] = nums[i]

            # Remove the oldest number from the bucket if we exceed indexDiff
            if i >= indexDiff:
                del buckets[nums[i - indexDiff] // bucket_size]

        return False        