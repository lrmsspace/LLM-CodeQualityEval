# There are an infinite amount of bags on a number line, one bag for each coordinate. Some of these bags contain coins.
# You are given a 2D array coins, where coins[i] = [li, ri, ci] denotes that every bag from li to ri contains ci coins.
# The segments that coins contain are non-overlapping.
# You are also given an integer k.
# Return the maximum amount of coins you can obtain by collecting k consecutive bags.
# Example 1:
# Input: coins = [[8,10,1],[1,3,2],[5,6,4]], k = 4
# Output: 10
# Explanation:
# Selecting bags at positions [3, 4, 5, 6] gives the maximum number of coins: 2 + 0 + 4 + 4 = 10.
# Example 2:
# Input: coins = [[1,10,3]], k = 2
# Output: 6
# Explanation:
# Selecting bags at positions [1, 2] gives the maximum number of coins: 3 + 3 = 6.
# Constraints:
# 1 <= coins.length <= 105
# 1 <= k <= 109
# coins[i] == [li, ri, ci]
# 1 <= li <= ri <= 109
# 1 <= ci <= 1000
# The given segments are non-overlapping.

class Solution(object):
    def maximumCoins(self, coins, k):
        """
        :type coins: List[List[int]]
        :type k: int
        :rtype: int
        """
        events = []
        for li, ri, ci in coins:
            events.append((li, ci))
            events.append((ri + 1, -ci))
        events.sort()

        max_coins = 0
        current_coins = 0
        prev_position = -float('inf')
        coin_counts = []

        for position, value in events:
            if position != prev_position:
                coin_counts.append((prev_position, current_coins))
                prev_position = position
            current_coins += value

        left = 0
        current_sum = 0
        for right in range(1, len(coin_counts)):
            current_sum += (coin_counts[right][0] - coin_counts[right - 1][0]) * coin_counts[right - 1][1]
            while coin_counts[right][0] - coin_counts[left][0] >= k:
                current_sum -= (coin_counts[left + 1][0] - coin_counts[left][0]) * coin_counts[left][1]
                left += 1
            max_coins = max(max_coins, current_sum)

        return max_coins

