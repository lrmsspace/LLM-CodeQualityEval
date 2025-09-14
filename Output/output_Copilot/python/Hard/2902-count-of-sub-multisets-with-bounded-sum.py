# You are given a 0-indexed array nums of non-negative integers, and two integers l and r.
# Return the count of sub-multisets within nums where the sum of elements in each subset falls within the inclusive range of [l, r].
# Since the answer may be large, return it modulo 109 + 7.
# A sub-multiset is an unordered collection of elements of the array in which a given value x can occur 0, 1, ..., occ[x] times, where occ[x] is the number of occurrences of x in the array.
# Note that:
# Two sub-multisets are the same if sorting both sub-multisets results in identical multisets.
# The sum of an empty multiset is 0.
# Example 1:
# Input: nums = [1,2,2,3], l = 6, r = 6
# Output: 1
# Explanation: The only subset of nums that has a sum of 6 is {1, 2, 3}.
# Example 2:
# Input: nums = [2,1,4,2,7], l = 1, r = 5
# Output: 7
# Explanation: The subsets of nums that have a sum within the range [1, 5] are {1}, {2}, {4}, {2, 2}, {1, 2}, {1, 4}, and {1, 2, 2}.
# Example 3:
# Input: nums = [1,2,1,3,5,2], l = 3, r = 5
# Output: 9
# Explanation: The subsets of nums that have a sum within the range [3, 5] are {3}, {5}, {1, 2}, {1, 3}, {2, 2}, {2, 3}, {1, 1, 2}, {1, 1, 3}, and {1, 2, 2}.
# Constraints:
# 1 <= nums.length <= 2 * 104
# 0 <= nums[i] <= 2 * 104
# Sum of nums does not exceed 2 * 104.
# 0 <= l <= r <= 2 * 104

class Solution(object):
    def countSubMultisets(self, nums, l, r):
        """
        :type nums: List[int]
        :type l: int
        :type r: int
        :rtype: int
        """
        from collections import Counter

        MOD = 10**9 + 7
        count = Counter(nums)
        unique_nums = list(count.keys())
        n = len(unique_nums)

        # dp[i][j] will store the number of ways to form a sum j using the first i unique numbers
        dp = [[0] * (r + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            num = unique_nums[i - 1]
            max_occurrences = count[num]
            for j in range(r + 1):
                dp[i][j] = dp[i - 1][j]
                for k in range(1, max_occurrences + 1):
                    if j >= k * num:
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - k * num]) % MOD
        # Count the number of valid sums in the range [l, r]
        result = 0
        for j in range(l, r + 1):
            result = (result + dp[n][j]) % MOD
        return result
            