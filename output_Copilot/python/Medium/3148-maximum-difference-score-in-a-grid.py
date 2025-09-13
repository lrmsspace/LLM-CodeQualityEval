# You are given an m x n matrix grid consisting of positive integers. You can move from a cell in the matrix to any other cell that is either to the bottom or to the right (not necessarily adjacent). The score of a move from a cell with the value c1 to a cell with the value c2 is c2 - c1.
# You can start at any cell, and you have to make at least one move.
# Return the maximum total score you can achieve.
# Example 1:
# Input: grid = [[9,5,7,3],[8,9,6,1],[6,7,14,3],[2,5,3,1]]
# Output: 9
# Explanation: We start at the cell (0, 1), and we perform the following moves:
# - Move from the cell (0, 1) to (2, 1) with a score of 7 - 5 = 2.
# - Move from the cell (2, 1) to (2, 2) with a score of 14 - 7 = 7.
# The total score is 2 + 7 = 9.
# Example 2:
# Input: grid = [[4,3,2],[3,2,1]]
# Output: -1
# Explanation: We start at the cell (0, 0), and we perform one move: (0, 0) to (0, 1). The score is 3 - 4 = -1.
# Constraints:
# m == grid.length
# n == grid[i].length
# 2 <= m, n <= 1000
# 4 <= m * n <= 105
# 1 <= grid[i][j] <= 105

class Solution(object):
    def maxScore(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        m = len(grid)
        n = len(grid[0])
        max_score = float('-inf')

        # Iterate through all possible starting points
        for i in range(m):
            for j in range(n):
                # Calculate the score for the current starting point
                score = 0
                x1 = i
                y1 = j
                while x1 < m and y1 < n:
                    score += grid[x1][y1] - grid[i][j]
                    x1 += 1
                    y1 += 1
                max_score = max(max_score, score)

        return max_score