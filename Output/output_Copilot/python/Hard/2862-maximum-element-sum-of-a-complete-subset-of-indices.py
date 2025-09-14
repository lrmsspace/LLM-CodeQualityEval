# You are given a 1-indexed array nums. Your task is to select a complete subset from nums where every pair of selected indices multiplied is a perfect square,. i. e. if you select ai and aj, i * j must be a perfect square.
# Return the sum of the complete subset with the maximum sum.
# Example 1:
# Input: nums = [8,7,3,5,7,2,4,9]
# Output: 16
# Explanation:
# We select elements at indices 2 and 8 and 2 * 8 is a perfect square.
# Example 2:
# Input: nums = [8,10,3,8,1,13,7,9,4]
# Output: 20
# Explanation:
# We select elements at indices 1, 4, and 9. 1 * 4, 1 * 9, 4 * 9 are perfect squares.
# Constraints:
# 1 <= n == nums.length <= 104
# 1 <= nums[i] <= 109

class Solution(object):
    def maximumSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import defaultdict
        import math

        n = len(nums)
        dp = [0] * (n + 1)
        index_map = defaultdict(list)

        # Step 1: Group indices by their square root factors
        for i in range(1, n + 1):
            sqrt_i = int(math.sqrt(i))
            for j in range(1, sqrt_i + 1):
                if i % j == 0:
                    index_map[j].append(i)
                    if j != i // j:
                        index_map[i // j].append(i)

        # Step 2: Calculate maximum sum for each group of indices
        max_sum = 0
        for key, indices in index_map.items():
            current_sum = sum(nums[i - 1] for i in indices)
            max_sum = max(max_sum, current_sum)

        return max_sum        