# You are given three integers n, m, k. A good array arr of size n is defined as follows:
# Each element in arr is in the inclusive range [1, m].
# Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
# Return the number of good arrays that can be formed.
# Since the answer may be very large, return it modulo 109 + 7.
# Example 1:
# Input: n = 3, m = 2, k = 1
# Output: 4
# Explanation:
# There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2, 2, 1].
# Hence, the answer is 4.
# Example 2:
# Input: n = 4, m = 2, k = 2
# Output: 6
# Explanation:
# The good arrays are [1, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 2], [2, 1, 1, 1], [2, 2, 1, 1] and [2, 2, 2, 1].
# Hence, the answer is 6.
# Example 3:
# Input: n = 5, m = 2, k = 0
# Output: 2
# Explanation:
# The good arrays are [1, 2, 1, 2, 1] and [2, 1, 2, 1, 2]. Hence, the answer is 2.
# Constraints:
# 1 <= n <= 105
# 1 <= m <= 105
# 0 <= k <= n - 1

class Solution(object):
    def countGoodArrays(self, n, m, k):
        """
        :type n: int
        :type m: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9 + 7
        
        # Base case: if k is 0, we can only have two distinct values
        if k == 0:
            return 2 if m >= 2 else 1
        
        # Calculate the number of ways to choose k positions for equal elements
        from math import comb
        
        # Total ways to choose k positions from n-1
        ways_to_choose_k = comb(n - 1, k) % MOD
        
        # Each of the k positions can be filled with any of the m values
        # The remaining n - 1 - k positions can be filled with m - 1 values
        total_ways = (ways_to_choose_k * pow(m, k, MOD) * pow(m - 1, n - 1 - k, MOD)) % MOD
        
        return total_ways
        