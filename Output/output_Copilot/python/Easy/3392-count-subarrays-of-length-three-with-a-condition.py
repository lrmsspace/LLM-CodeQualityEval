# Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.
# Example 1:
# Input: nums = [1,2,1,4,1]
# Output: 1
# Explanation:
# Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.
# Example 2:
# Input: nums = [1,1,1]
# Output: 0
# Explanation:
# [1,1,1] is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.
# Constraints:
# 3 <= nums.length <= 100
# -100 <= nums[i] <= 100

class Solution(object):
    def countSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        n = len(nums)
        
        # Iterate through the array to find subarrays of length 3
        for i in range(n - 2):
            # Check if the sum of the first and third elements equals half of the second element
            if nums[i] + nums[i + 2] == nums[i + 1] / 2:
                count += 1
                
        return count
        