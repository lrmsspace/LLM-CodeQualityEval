# You are given a 0-indexed 2D integer matrix grid of size 3 * 3, representing the number of stones in each cell. The grid contains exactly 9 stones, and there can be multiple stones in a single cell.
# In one move, you can move a single stone from its current cell to any other cell if the two cells share a side.
# Return the minimum number of moves required to place one stone in each cell.
# Example 1:
# Input: grid = [[1,1,0],[1,1,1],[1,2,1]]
# Output: 3
# Explanation: One possible sequence of moves to place one stone in each cell is: 
# 1- Move one stone from cell (2,1) to cell (2,2).
# 2- Move one stone from cell (2,2) to cell (1,2).
# 3- Move one stone from cell (1,2) to cell (0,2).
# In total, it takes 3 moves to place one stone in each cell of the grid.
# It can be shown that 3 is the minimum number of moves required to place one stone in each cell.
# Example 2:
# Input: grid = [[1,3,0],[1,0,0],[1,0,3]]
# Output: 4
# Explanation: One possible sequence of moves to place one stone in each cell is:
# 1- Move one stone from cell (0,1) to cell (0,2).
# 2- Move one stone from cell (0,1) to cell (1,1).
# 3- Move one stone from cell (2,2) to cell (1,2).
# 4- Move one stone from cell (2,2) to cell (2,1).
# In total, it takes 4 moves to place one stone in each cell of the grid.
# It can be shown that 4 is the minimum number of moves required to place one stone in each cell.
# Constraints:
# grid.length == grid[i].length == 3
# 0 <= grid[i][j] <= 9
# Sum of grid is equal to 9.

class Solution(object):
    def minimumMoves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        # Calculate the total number of stones
        total_stones = sum(sum(row) for row in grid)

        # Calculate the target number of stones per cell
        target = total_stones // 9

        # Create a variable to store the number of moves
        moves = 0

        # Iterate through the grid and calculate the number of moves
        for i in range(3):
            for j in range(3):
                # Calculate the difference between the current cell and the target
                diff = grid[i][j] - target
                # If the difference is positive, we need to move stones out
                if diff > 0:
                    moves += diff

        return moves
