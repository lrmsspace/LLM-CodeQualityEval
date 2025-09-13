# You are given an integer array coins representing coins of different denominations and an integer k.
# You have an infinite number of coins of each denomination. However, you are not allowed to combine coins of different denominations.
# Return the kth smallest amount that can be made using these coins.
# Example 1:
# Input: coins = [3,6,9], k = 3
# Output:  9
# Explanation: The given coins can make the following amounts:
# Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.
# Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.
# Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.
# All of the coins combined produce: 3, 6, 9, 12, 15, etc.
# Example 2:
# Input: coins = [5,2], k = 7
# Output: 12 
# Explanation: The given coins can make the following amounts:
# Coin 5 produces multiples of 5: 5, 10, 15, 20, etc.
# Coin 2 produces multiples of 2: 2, 4, 6, 8, 10, 12, etc.
# All of the coins combined produce: 2, 4, 5, 6, 8, 10, 12, 14, 15, etc.
# Constraints:
# 1 <= coins.length <= 15
# 1 <= coins[i] <= 25
# 1 <= k <= 2 * 109
# coins contains pairwise distinct integers.

from itertools import combinations

class Solution(object):
    def findKthSmallest(self, coins, k):
        """
        :type coins: List[int]
        :type k: int
        :rtype: int
        """
        # 计算在 [1, mid] 范围内能被 coins 中至少一个硬币整除的数的个数
        def count_le(mid, coins):
            res = 0
            n = len(coins)
            for i in range(1, n + 1):
                for comb in combinations(coins, i):
                    lcm = 1
                    for num in comb:
                        from math import gcd
                        lcm = lcm * num // gcd(lcm, num)
                    if i % 2 == 1:
                        res += mid // lcm
                    else:
                        res -= mid // lcm
            return res
        
        left, right = 1, 10**18
        while left < right:
            mid = (left + right) // 2
            if count_le(mid, coins) < k:
                left = mid + 1
            else:
                right = mid
        return left