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
        n = len(grid[0]) if m > 0 else 0

        # Create a prefix sum array for 'X' and 'Y'
        prefixX = [[0] * (n + 1) for _ in range(m + 1)]
        prefixY = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                prefixX[i][j] = prefixX[i - 1][j] + prefixX[i][j - 1] - prefixX[i - 1][j - 1]
                prefixY[i][j] = prefixY[i - 1][j] + prefixY[i][j - 1] - prefixY[i - 1][j - 1]
                if grid[i - 1][j - 1] == 'X':
                    prefixX[i][j] += 1
                elif grid[i - 1][j - 1] == 'Y':
                    prefixY[i][j] += 1

        count = 0
        # Iterate over all possible submatrices
        for r1 in range(1, m + 1):
            for r2 in range(r1, m + 1):
                for c1 in range(1, n + 1):
                    for c2 in range(c1, n + 1):
                        # Get the count of 'X' and 'Y' in the current submatrix
                        countX = prefixX[r2][c2] - prefixX[r1 - 1][c2] - prefixX[r2][c1 - 1] + prefixX[r1 - 1][c1 - 1]
                        countY = prefixY[r2][c2] - prefixY[r1 - 1][c2] - prefixY[r2][c1 - 1] + prefixY[r1 - 1][c1 - 1]
                        # Check if the submatrix is valid
                        if countX == countY and countX > 0:
                            count += 1

        return count