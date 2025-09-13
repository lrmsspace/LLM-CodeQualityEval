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
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 'X':
                    xCount = 0
                    yCount = 0
                    for k in range(i, len(grid)):
                        for col in range(j, len(grid[0])):
                            if grid[k][col] == 'X':
                                xCount += 1
                            elif grid[k][col] == 'Y':
                                yCount += 1
                        if xCount == yCount and xCount > 0:
                            count += 1
        return count
