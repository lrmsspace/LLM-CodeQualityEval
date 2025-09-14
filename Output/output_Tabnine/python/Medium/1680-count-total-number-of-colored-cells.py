#https://leetcode.com/problems/count-total-number-of-colored-cells/
#There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:
#	At the first minute, color any arbitrary unit cell blue.
#	Every minute thereafter, color blue every uncolored cell that touches a blue cell.
#Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.
#Return the number of colored cells at the end of n minutes.
# 
#Example 1:
#Input: n = 1
#Output: 1
#Explanation: After 1 minute, there is only 1 blue cell, so we return 1.
#Example 2:
#Input: n = 2
#Output: 5
#Explanation: After 2 minutes, there are 4 colored cells on the boundary and 1 in the center, so we return 5. 
# 
#Constraints:
#	1 <= n <= 105
class Solution(object):
    def coloredCells(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Initialize a 2D list to store the color status of each cell
        color_grid = [[False] * n for _ in range(n)]
        # Set the color of the first cell blue
        color_grid[0][0] = True
        # Define a helper function to check if a cell is within the grid boundaries
        def is_valid(x, y):
            return 0 <= x < n and 0 <= y < n
        
        # Define a helper function to color blue cells that touch a blue cell
        def color_cells(x, y):
            color_grid[x][y] = True
            # Check the neighboring cells
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]:
                nx, ny = x + dx, y + dy
                if is_valid(nx, ny) and not color_grid[nx][ny]:
                    color_cells(nx, ny)
        
        # Color blue cells that touch a blue cell at the first minute
        color_cells(0, 0)
        
        # Count the number of colored cells
        colored_cells_count = sum(row.count(True) for row in color_grid)
        
        return colored_cells_count

        