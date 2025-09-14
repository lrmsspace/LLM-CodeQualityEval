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
        m = len(grid)
        n = len(grid[0])
        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 'X':
                    count += 1
                    if i > 0 and j > 0 and grid[i-1][j] == 'X' and grid[i][j-1] == 'X' and grid[i-1][j-1] == 'X':
                        count += 1
        return count        