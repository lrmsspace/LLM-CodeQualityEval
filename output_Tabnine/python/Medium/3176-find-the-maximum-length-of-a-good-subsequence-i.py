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
# 1 <= nums.length <= 500
# 1 <= nums[i] <= 109
# 0 <= k <= min(nums.length, 25)

class Solution(object):
    def maximumLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # Initialize variables
        n = len(nums)
        dp = [1] * n
        left = [0] * n
        right = [0] * n
        
        # Find the longest increasing subsequence ending at each index
        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        
        # Find the longest decreasing subsequence ending at each index
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        
        # Find the longest increasing subsequence that ends at each index
        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j] and dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1
        
        # Find the longest decreasing subsequence that ends at each index
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if nums[i] < nums[j] and dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1
        
        # Find the maximum length of a good subsequence
        max_length = 0
        for i in range(n):
            max_length = max(max_length, dp[i] + right[i] + left[i] - 1)
        
        return max_length