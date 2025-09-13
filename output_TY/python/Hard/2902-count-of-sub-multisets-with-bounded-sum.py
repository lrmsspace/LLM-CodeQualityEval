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
    
from collections import Counter

MOD = 10 ** 9 + 7

class Solution(object):
    def countSubMultisets(self, nums, l, r):
        """
        :type nums: List[int]
        :type l: int
        :type r: int
        :rtype: int
        """
        from collections import defaultdict
        
        # 统计每个数字的出现次数
        counter = Counter(nums)
        
        # dp[sum] 表示和为 sum 的子-multiset 的数量
        dp = defaultdict(int)
        dp[0] = 1  # 初始状态：和为 0 的情况只有一种（空集）

        for num, cnt in counter.items():
            new_dp = defaultdict(int)
            for s in range(r + 1):
                if dp[s] == 0:
                    continue
                # 不选当前 num
                new_dp[s] = (new_dp[s] + dp[s]) % MOD
                # 选 1~cnt 个 num
                for k in range(1, cnt + 1):
                    if s + k * num > r:
                        break
                    new_dp[s + k * num] = (new_dp[s + k * num] + dp[s]) % MOD
            dp = new_dp

        # 统计 l <= sum <= r 的所有情况
        result = sum(dp[sum_val] for sum_val in range(l, r + 1)) % MOD
        return result
