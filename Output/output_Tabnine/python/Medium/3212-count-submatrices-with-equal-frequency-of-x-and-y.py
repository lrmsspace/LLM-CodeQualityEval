# Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
# grid[0][0]
# an equal frequency of 'X' and 'Y'.
# at least one 'X'.
# Example 1:
# Input: grid = [["X","Y","."],["Y",".","."]]
# Output: 3
# Explanation:
# Example 2:
# Input: grid = [["X","X"],["X","Y"]]
# Output: 0
# Explanation:
# No submatrix has an equal frequency of 'X' and 'Y'.
# Example 3:
# Input: grid = [[".","."],[".","."]]
# Output: 0
# Explanation:
# No submatrix has at least one 'X'.
# Constraints:
# 1 <= grid.length, grid[i].length <= 1000
# grid[i][j] is either 'X', 'Y', or '.'.

class Solution(object):
    def numberOfSubmatrices(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        rows, cols = len(grid), len(grid[0])
        dp = [[0] * (cols + 1) for _ in range(rows + 1)]
        res = 0
        
        for i in range(1, rows + 1):
            for j in range(1, cols + 1):
                if grid[i - 1][j - 1] == 'X':
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]
        
        for i in range(1, rows + 1):
            for j in range(i, rows + 1):
                for k in range(1, cols + 1):
                    if dp[j][k] - dp[i - 1][k] - dp[j][k - 1] + dp[i - 1][k - 1] == j - i + 1:
                        res += 1
        return res
        