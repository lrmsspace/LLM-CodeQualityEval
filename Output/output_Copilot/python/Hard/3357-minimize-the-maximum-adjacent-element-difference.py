# You are given an array of integers nums. Some values in nums are missing and are denoted by -1.
# You must choose a pair of positive integers (x, y) exactly once and replace each missing element with either x or y.
# You need to minimize the maximum absolute difference between adjacent elements of nums after replacements.
# Return the minimum possible difference.
# Example 1:
# Input: nums = [1,2,-1,10,8]
# Output: 4
# Explanation:
# By choosing the pair as (6, 7), nums can be changed to [1, 2, 6, 10, 8].
# The absolute differences between adjacent elements are:
# |1 - 2| == 1
# |2 - 6| == 4
# |6 - 10| == 4
# |10 - 8| == 2
# Example 2:
# Input: nums = [-1,-1,-1]
# Output: 0
# Explanation:
# By choosing the pair as (4, 4), nums can be changed to [4, 4, 4].
# Example 3:
# Input: nums = [-1,10,-1,8]
# Output: 1
# Explanation:
# By choosing the pair as (11, 9), nums can be changed to [11, 10, 9, 8].
# Constraints:
# 2 <= nums.length <= 105
# nums[i] is either -1 or in the range [1, 109].

class Solution(object):
    def minDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import defaultdict
        import math

        n = len(nums)
        if n < 2:
            return 0

        # Find the minimum and maximum values in nums
        min_val = float('inf')
        max_val = float('-inf')
        missing_indices = []

        for i, num in enumerate(nums):
            if num == -1:
                missing_indices.append(i)
            else:
                min_val = min(min_val, num)
                max_val = max(max_val, num)

        # If there are no missing values, return the maximum difference
        if not missing_indices:
            return max_val - min_val

        # Calculate the range of possible values for x and y
        possible_values = set(range(min_val, max_val + 1))

        # Check all pairs of possible values (x, y)
        min_difference = float('inf')

        for x in possible_values:
            for y in possible_values:
                if x == y:
                    continue

                # Replace missing values with x and y
                modified_nums = nums[:]
                for idx in missing_indices:
                    modified_nums[idx] = x if idx % 2 == 0 else y

                # Calculate the maximum absolute difference
                max_diff = 0
                for i in range(1, n):
                    max_diff = max(max_diff, abs(modified_nums[i] - modified_nums[i - 1]))

                min_difference = min(min_difference, max_diff)

        return min_difference
        