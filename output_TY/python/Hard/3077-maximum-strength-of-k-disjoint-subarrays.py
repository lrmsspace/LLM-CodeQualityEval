# You are given an array of integers nums with length n, and a positive odd integer k.
# Select exactly k disjoint subarrays sub1, sub2, ..., subk from nums such that the last element of subi appears before the first element of sub{i+1} for all 1 <= i <= k-1. The goal is to maximize their combined strength.
# The strength of the selected subarrays is defined as:
# strength = k * sum(sub1)- (k - 1) * sum(sub2) + (k - 2) * sum(sub3) - ... - 2 * sum(sub{k-1}) + sum(subk)
# where sum(subi) is the sum of the elements in the i-th subarray.
# Return the maximum possible strength that can be obtained from selecting exactly k disjoint subarrays from nums.
# Note that the chosen subarrays don't need to cover the entire array.
# Example 1:
# Input: nums = [1,2,3,-1,2], k = 3
# Output: 22
# Explanation:
# The best possible way to select 3 subarrays is: nums[0..2], nums[3..3], and nums[4..4]. The strength is calculated as follows:
# strength = 3 * (1 + 2 + 3) - 2 * (-1) + 2 = 22
# Example 2:
# Input: nums = [12,-2,-2,-2,-2], k = 5
# Output: 64
# Explanation:
# The only possible way to select 5 disjoint subarrays is: nums[0..0], nums[1..1], nums[2..2], nums[3..3], and nums[4..4]. The strength is calculated as follows:
# strength = 5 * 12 - 4 * (-2) + 3 * (-2) - 2 * (-2) + (-2) = 64
# Example 3:
# Input: nums = [-1,-2,-3], k = 1
# Output: -1
# Explanation:
# The best possible way to select 1 subarray is: nums[0..0]. The strength is -1.
# Constraints:
# 1 <= n <= 104
# -109 <= nums[i] <= 109
# 1 <= k <= n
# 1 <= n * k <= 106
# k is odd.

class Solution(object):
    def maximumStrength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        # 系数权重，依次为 k, k-1, ..., 1
        weight = [k - i for i in range(k)]

        # 初始化两个一维数组，保存当前层和上一层的最大值
        prev = [-float('inf')] * (k + 1)
        curr = [0] * (k + 1)

        prev[0] = 0  # 前0个子数组总强度为0

        for i in range(n):
            curr = [-float('inf')] * (k + 1)
            curr[0] = 0  # 每轮开始前设置0个子数组的强度为0
            for j in range(1, k + 1):
                # 继续扩展当前子数组或新开一个子数组
                extend = prev[j] + weight[j - 1] * nums[i]
                start_new = prev[j - 1] + weight[j - 1] * nums[i]
                curr[j] = max(extend, start_new)
            prev = curr

        return max(prev[1:])  # 至少选一个子数组到选k个子数组中的最大值       