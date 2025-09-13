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
        from itertools import permutations
        
        n = len(grid)
        m = len(grid[0])
        max_score = 0
        
        # Generate all permutations of column indices
        for perm in permutations(range(m), n):
            current_score = sum(grid[i][perm[i]] for i in range(n))
            max_score = max(max_score, current_score)
        
        return max_score
        