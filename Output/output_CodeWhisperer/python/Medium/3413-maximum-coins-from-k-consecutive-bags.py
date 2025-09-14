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
        # Sort the bags by their start position
        coins.sort(key=lambda x: x[0])
        
        # Initialize a list to store the maximum coins for each position
        dp = [0] * (coins[-1][1] + 1)
        
        # Iterate through each bag
        for start, end, coins_in_bag in coins:
            # Update the maximum coins for each position within the bag's range
            for i in range(start, end + 1):
                dp[i] = max(dp[i], dp[i - 1] + coins_in_bag)
        
        # Return the maximum coins for the last k positions
        return max(dp[-k:])        