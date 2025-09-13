# You are given a 2D integer array grid with size m x n. You are also given an integer k.
# Your task is to calculate the number of paths you can take from the top-left cell (0, 0) to the bottom-right cell (m - 1, n - 1) satisfying the following constraints:
# You can either move to the right or down. Formally, from the cell (i, j) you may move to the cell (i, j + 1) or to the cell (i + 1, j) if the target cell exists.
# The XOR of all the numbers on the path must be equal to k.
# Return the total number of such paths.
# Since the answer can be very large, return the result modulo 109 + 7.
# Example 1:
# Input: grid = [[2, 1, 5], [7, 10, 0], [12, 6, 4]], k = 11
# Output: 3
# Explanation: 
# The 3 paths are:
# (0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2)
# (0, 0) → (1, 0) → (1, 1) → (1, 2) → (2, 2)
# (0, 0) → (0, 1) → (1, 1) → (2, 1) → (2, 2)
# Example 2:
# Input: grid = [[1, 3, 3, 3], [0, 3, 3, 2], [3, 0, 1, 1]], k = 2
# Output: 5
# Explanation:
# The 5 paths are:
# (0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2) → (2, 3)
# (0, 0) → (1, 0) → (1, 1) → (2, 1) → (2, 2) → (2, 3)
# (0, 0) → (1, 0) → (1, 1) → (1, 2) → (1, 3) → (2, 3)
# (0, 0) → (0, 1) → (1, 1) → (1, 2) → (2, 2) → (2, 3)
# (0, 0) → (0, 1) → (0, 2) → (1, 2) → (2, 2) → (2, 3)
# Example 3:
# Input: grid = [[1, 1, 1, 2], [3, 0, 3, 2], [3, 0, 2, 2]], k = 10
# Output: 0
# Constraints:
# 1 <= m == grid.length <= 300
# 1 <= n == grid[r].length <= 300
# 0 <= grid[r][c] < 16
# 0 <= k < 16

class Solution(object):
    def countPathsWithXorValue(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        MOD = 10**9 + 7
        m, n = len(grid), len(grid[0])

        # dp[i][j][xor_value] stores the number of ways to reach cell (i, j) with a XOR value of xor_value
        dp = [[[0] * 16 for _ in range(n)] for _ in range(m)]

        # Initialize starting point
        dp[0][0][grid[0][0]] = 1

        for i in range(m):
            for j in range(n):
                for xor_value in range(16):
                    if dp[i][j][xor_value] > 0:
                        if i + 1 < m:
                            new_xor = xor_value ^ grid[i + 1][j]
                            dp[i + 1][j][new_xor] = (dp[i + 1][j][new_xor] + dp[i][j][xor_value]) % MOD
                        if j + 1 < n:
                            new_xor = xor_value ^ grid[i][j + 1]
                            dp[i][j + 1][new_xor] = (dp[i][j + 1][new_xor] + dp[i][j][xor_value]) % MOD

        return dp[m - 1][n - 1][k]

