# You are given an integer array nums.
# You can do the following operation on the array at most once:
# Choose any integer x such that nums remains non-empty on removing all occurrences of x.
# Remove all occurrences of x from the array.
# Return the maximum subarray sum across all possible resulting arrays.
# Example 1:
# Input: nums = [-3,2,-2,-1,3,-2,3]
# Output: 7
# Explanation:
# We can have the following arrays after at most one operation:
# The original array is nums = [-3, 2, -2, -1, 3, -2, 3]. The maximum subarray sum is 3 + (-2) + 3 = 4.
# Deleting all occurences of x = -3 results in nums = [2, -2, -1, 3, -2, 3]. The maximum subarray sum is 3 + (-2) + 3 = 4.
# Deleting all occurences of x = -2 results in nums = [-3, 2, -1, 3, 3]. The maximum subarray sum is 2 + (-1) + 3 + 3 = 7.
# Deleting all occurences of x = -1 results in nums = [-3, 2, -2, 3, -2, 3]. The maximum subarray sum is 3 + (-2) + 3 = 4.
# Deleting all occurences of x = 3 results in nums = [-3, 2, -2, -1, -2]. The maximum subarray sum is 2.
# The output is max(4, 4, 7, 4, 2) = 7.
# Example 2:
# Input: nums = [1,2,3,4]
# Output: 10
# Explanation:
# It is optimal to not perform any operations.
# Constraints:
# 1 <= nums.length <= 105
# -106 <= nums[i] <= 106

class Solution(object):
    def maxSubarraySum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import defaultdict
        
        # Step 1: Calculate the maximum subarray sum without any removals
        def kadane(arr):
            max_sum = current_sum = arr[0]
            for num in arr[1:]:
                current_sum = max(num, current_sum + num)
                max_sum = max(max_sum, current_sum)
            return max_sum
        
        max_without_removal = kadane(nums)
        
        # Step 2: Calculate the maximum subarray sum after removing all occurrences of each element
        element_indices = defaultdict(list)
        for index, value in enumerate(nums):
            element_indices[value].append(index)
        
        max_with_removal = float('-inf')
        
        for value, indices in element_indices.items():
            if len(indices) == len(nums):
                continue
            # Create a new array excluding all occurrences of the current value
            new_array = [nums[i] for i in range(len(nums)) if nums[i] != value]
            max_with_removal = max(max_with_removal, kadane(new_array))
        # Step 3: Return the maximum of the two results
        return max(max_without_removal, max_with_removal)
        