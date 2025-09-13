# You are given two arrays nums and andValues of length n and m respectively.
# The value of an array is equal to the last element of that array.
# You have to divide nums into m disjoint contiguous subarrays such that for the ith subarray [li, ri], the bitwise AND of the subarray elements is equal to andValues[i], in other words, nums[li] & nums[li + 1] & ... & nums[ri] == andValues[i] for all 1 <= i <= m, where & represents the bitwise AND operator.
# Return the minimum possible sum of the values of the m subarrays nums is divided into. If it is not possible to divide nums into m subarrays satisfying these conditions, return -1.
# Example 1:
# Input: nums = [1,4,3,3,2], andValues = [0,3,3,2]
# Output: 12
# Explanation:
# The only possible way to divide nums is:
# [1,4] as 1 & 4 == 0.
# [3] as the bitwise AND of a single element subarray is that element itself.
# [3] as the bitwise AND of a single element subarray is that element itself.
# [2] as the bitwise AND of a single element subarray is that element itself.
# The sum of the values for these subarrays is 4 + 3 + 3 + 2 = 12.
# Example 2:
# Input: nums = [2,3,5,7,7,7,5], andValues = [0,7,5]
# Output: 17
# Explanation:
# There are three ways to divide nums:
# [[2,3,5],[7,7,7],[5]] with the sum of the values 5 + 7 + 5 == 17.
# [[2,3,5,7],[7,7],[5]] with the sum of the values 7 + 7 + 5 == 19.
# [[2,3,5,7,7],[7],[5]] with the sum of the values 7 + 7 + 5 == 19.
# The minimum possible sum of the values is 17.
# Example 3:
# Input: nums = [1,2,3,4], andValues = [2]
# Output: -1
# Explanation:
# The bitwise AND of the entire array nums is 0. As there is no possible way to divide nums into a single subarray to have the bitwise AND of elements 2, return -1.
# Constraints:
# 1 <= n == nums.length <= 104
# 1 <= m == andValues.length <= min(n, 10)
# 1 <= nums[i] < 105
# 0 <= andValues[j] < 105

class Solution(object):
    def minimumValueSum(self, nums, andValues):
        """
        :type nums: List[int]
        :type andValues: List[int]
        :rtype: int
        """
        n = len(nums)
        m = len(andValues)

        # dp[i][j]: 将前 i 个 nums 划分成 j 个子数组的最小末尾和
        INF = float('inf')
        dp = [[INF] * (m + 1) for _ in range(n + 1)]
        dp[0][0] = 0  # 初始状态

        for i in range(1, n + 1):  # 枚举当前处理到第 i 个 nums 元素
            curr_and = nums[i - 1]
            for j in range(i, 0, -1):  # 枚举当前子数组的起始位置
                curr_and &= nums[j - 1]
                if curr_and == andValues[k] if (k := len(andValues)) > 0 else False:
                    for k in range(1, m + 1):
                        if curr_and == andValues[k - 1]:
                            dp[i][k] = min(dp[i][k], dp[j - 1][k - 1] + nums[i - 1])
        
        res = dp[n][m]
        return res if res != INF else -1

        
        