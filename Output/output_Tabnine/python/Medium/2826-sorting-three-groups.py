# You are given an integer array nums. Each element in nums is 1, 2 or 3. In each operation, you can remove an element from nums. Return the minimum number of operations to make nums non-decreasing.
# Example 1:
# Input: nums = [2,1,3,2,1]
# Output: 3
# Explanation:
# One of the optimal solutions is to remove nums[0], nums[2] and nums[3].
# Example 2:
# Input: nums = [1,3,2,1,3,3]
# Output: 2
# Explanation:
# One of the optimal solutions is to remove nums[1] and nums[2].
# Example 3:
# Input: nums = [2,2,2,2,3,3]
# Output: 0
# Explanation:
# nums is already non-decreasing.
# Constraints:
# 1 <= nums.length <= 100
# 1 <= nums[i] <= 3
# Follow-up: Can you come up with an algorithm that runs in O(n) time complexity?

class Solution(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Initialize the count of operations to 0
        count = 0
        
        # Iterate over the array from left to right
        for i in range(1, len(nums)):
            # If the current element is smaller than the previous element,
            # then we need to replace it with the previous element or the next element
            # to make the array non-decreasing
            if nums[i] < nums[i-1]:
                # If the previous element is smaller than the next element,
                # then replace the current element with the next element
                if i > 1 and nums[i-2] < nums[i]:
                    nums[i-1] = nums[i]
                # Otherwise, replace the current element with the previous element
                else:
                    nums[i] = nums[i-1]
                # Increment the count of operations
                count += 1
        
        # Return the minimum number of operations
        return count
        