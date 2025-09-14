# You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
# Return the maximum possible length of a good subsequence of nums.
# Example 1:
# Input: nums = [1,2,1,1,3], k = 2
# Output: 4
# Explanation:
# The maximum length subsequence is [1,2,1,1,3].
# Example 2:
# Input: nums = [1,2,3,4,5,1], k = 0
# Output: 2
# Explanation:
# The maximum length subsequence is [1,2,3,4,5,1].
# Constraints:
# 1 <= nums.length <= 5 * 103
# 1 <= nums[i] <= 109
# 0 <= k <= min(50, nums.length)

class Solution(object):
    def maximumLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        n = len(nums)
        # Create a list to store the result
        result = [0] * n

        # Create a list to store the positions of each number
        positions = [[] for _ in range(n)]
        for i in range(n):
            positions[nums[i]].append(i)

        # Create a list to store the current position of each number
        current_positions = [0] * n
        for i in range(n):
            current_positions[nums[i]] = i

        # Find the permutation with the minimum cost
        for i in range(n):
            # Find the minimum position for the current number
            min_pos = min(positions[i])
            result[i] = min_pos
            # Update the positions of the current number
            positions[i].remove(min_pos)
            current_positions[i] = min_pos

        return result
