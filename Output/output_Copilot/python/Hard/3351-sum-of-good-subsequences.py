# You are given an integer array nums. A good subsequence is defined as a subsequence of nums where the absolute difference between any two consecutive elements in the subsequence is exactly 1.
# Return the sum of all possible good subsequences of nums.
# Since the answer may be very large, return it modulo 109 + 7.
# Note that a subsequence of size 1 is considered good by definition.
# Example 1:
# Input: nums = [1,2,1]
# Output: 14
# Explanation:
# Good subsequences are: [1], [2], [1], [1,2], [2,1], [1,2,1].
# The sum of elements in these subsequences is 14.
# Example 2:
# Input: nums = [3,4,5]
# Output: 40
# Explanation:
# Good subsequences are: [3], [4], [5], [3,4], [4,5], [3,4,5].
# The sum of elements in these subsequences is 40.
# Constraints:
# 1 <= nums.length <= 105
# 0 <= nums[i] <= 105

class Solution(object):
    def sumOfGoodSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import defaultdict

        MOD = 10**9 + 7
        freq = defaultdict(int)

        # Count frequency of each number
        for num in nums:
            freq[num] += 1

        total_sum = 0

        # Iterate through each unique number
        for num in sorted(freq.keys()):
            count = freq[num]
            # Calculate the contribution of subsequences ending with this number
            contribution = (num * pow(2, count, MOD)) % MOD
            total_sum = (total_sum + contribution) % MOD

            # If there's a previous number, add its contribution as well
            if num - 1 in freq:
                prev_count = freq[num - 1]
                total_sum = (total_sum + (num - 1) * pow(2, prev_count, MOD)) % MOD

        return total_sum
        