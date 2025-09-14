# You are given an integer array nums and a positive integer k.
# A subsequence sub of nums with length x is called valid if it satisfies:
# (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
# Return the length of the longest valid subsequence of nums.
# Example 1:
# Input: nums = [1,2,3,4,5], k = 2
# Output: 5
# Explanation:
# The longest valid subsequence is [1, 2, 3, 4, 5].
# Example 2:
# Input: nums = [1,4,2,3,1,4], k = 3
# Output: 4
# Explanation:
# The longest valid subsequence is [1, 4, 1, 4].
# Constraints:
# 2 <= nums.length <= 103
# 1 <= nums[i] <= 107
# 1 <= k <= 103

class Solution(object):
    def maximumLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        n = len(nums)
        if n == 0:
            return 0

        # Calculate the total cost without splitting
        total_cost = 0
        for i in range(n):
            total_cost += nums[i] if i % 2 == 0 else -nums[i]

        max_cost = total_cost

        # Try splitting the array at each index
        for i in range(n - 1):
            # Calculate the cost of the left subarray
            left_cost = sum(nums[j] if j % 2 == 0 else -nums[j] for j in range(i + 1))
            # Calculate the cost of the right subarray
            right_cost = sum(nums[j] if j % 2 == 0 else -nums[j] for j in range(i + 1, n))
            # Update the maximum cost
            max_cost = max(max_cost, left_cost + right_cost)

        return max_cost
