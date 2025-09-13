# You are given a 2D matrix grid consisting of positive integers.
# You have to select one or more cells from the matrix such that the following conditions are satisfied:
# No two selected cells are in the same row of the matrix.
# The values in the set of selected cells are unique.
# Your score will be the sum of the values of the selected cells.
# Return the maximum score you can achieve.
# Example 1:
# Input: grid = [[1,2,3],[4,3,2],[1,1,1]]
# Output: 8
# Explanation:
# We can select the cells with values 1, 3, and 4 that are colored above.
# Example 2:
# Input: grid = [[8,7,6],[8,3,2]]
# Output: 15
# Explanation:
# We can select the cells with values 7 and 8 that are colored above.
# Constraints:
# 1 <= grid.length, grid[i].length <= 10
# 1 <= grid[i][j] <= 100

class Solution(object):
    def maxScore(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        dp = [[0] * n for _ in range(m)]
        max_score = float('-inf')

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    dp[i][j] = grid[i][j]
                elif i == 0:
                    dp[i][j] = max(grid[i][j], dp[i][j - 1])
                elif j == 0:
                    dp[i][j] = max(grid[i][j], dp[i - 1][j])
                else:
                    dp[i][j] = max(grid[i][j], max(dp[i - 1][j], dp[i][j - 1]))

                if i > 0 and j > 0:
                    max_score = max(max_score, grid[i][j] - dp[i - 1][j - 1])

        return max_score

        