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

        # Create a list to store the number of coins in each bag
        bags = [0] * (k + 1)

        # Distribute the coins into the bags
        for l, r, c in coins:
            bags[l] += c
            if r + 1 <= k:
                bags[r + 1] -= c

        # Calculate the prefix sum to get the actual number of coins in each bag
        for i in range(1, k + 1):
            bags[i] += bags[i - 1]

        # Find the maximum number of coins in k consecutive bags
        max_coins = 0
        current_coins = sum(bags[1:k + 1])
        max_coins = max(max_coins, current_coins)

        for i in range(k + 1, len(bags)):
            current_coins += bags[i] - bags[i - k - 1]
            max_coins = max(max_coins, current_coins)

        return max_coins