# Given an array nums, you can perform the following operation any number of times:
# Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
# Replace the pair with their sum.
# Return the minimum number of operations needed to make the array non-decreasing.
# An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).
# Example 1:
# Input: nums = [5,2,3,1]
# Output: 2
# Explanation:
# The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
# The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
# The array nums became non-decreasing in two operations.
# Example 2:
# Input: nums = [1,2,2]
# Output: 0
# Explanation:
# The array nums is already sorted.
# Constraints:
# 1 <= nums.length <= 50
# -1000 <= nums[i] <= 1000

class Solution(object):
    def minimumPairRemoval(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        while any(nums[i] > nums[i - 1] for i in range(1, len(nums))):
            min_sum = float('inf')
            min_index = -1
            for i in range(1, len(nums)):
                current_sum = nums[i] + nums[i - 1]
                if current_sum < min_sum:
                    min_sum = current_sum
                    min_index = i

            nums[min_index - 1] = min_sum
            nums.pop(min_index)
            count += 1

        return count

