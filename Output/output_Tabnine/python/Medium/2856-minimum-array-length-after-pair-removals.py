# Given an integer array num sorted in non-decreasing order.
# You can perform the following operation any number of times:
# Choose two indices, i and j, where nums[i] < nums[j].
# Then, remove the elements at indices i and j from nums. The remaining elements retain their original order, and the array is re-indexed.
# Return the minimum length of nums after applying the operation zero or more times.
# Example 1:
# Input: nums = [1,2,3,4]
# Output: 0
# Explanation:
# Example 2:
# Input: nums = [1,1,2,2,3,3]
# Output: 0
# Explanation:
# Example 3:
# Input: nums = [1000000000,1000000000]
# Output: 2
# Explanation:
# Since both numbers are equal, they cannot be removed.
# Example 4:
# Input: nums = [2,3,4,4,4]
# Output: 1
# Explanation:
# Constraints:
# 1 <= nums.length <= 105
# 1 <= nums[i] <= 109
# nums is sorted in non-decreasing order.

class Solution(object):
    def minLengthAfterRemovals(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        i, j = 0, n - 1
        
        while i < j:
            if nums[i] == nums[j]:
                while i < j and nums[i] == nums[i + 1]:
                    i += 1
                while i < j and nums[j] == nums[j - 1]:
                    j -= 1
                if nums[i] == nums[j]:
                    return n
                else:
                    return n - 2
            elif nums[i] < nums[j]:
                i += 1
            else:
                j -= 1
        
        return n - 1    
        