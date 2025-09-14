#https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
#Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
#A grid is said to be valid if all the cells above the main diagonal are zeros.
#Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
#The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).
# 
#Example 1:
#Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
#Output: 3
#Example 2:
#Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
#Output: -1
#Explanation: All rows are similar, swaps have no effect on the grid.
#Example 3:
#Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
#Output: 0
# 
#Constraints:
#	n == grid.length == grid[i].length
#	1 <= n <= 200
#	grid[i][j] is either 0 or 1
class Solution(object):
    def minSwaps(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # Find the first row with a 1
        row_with_one = next((i for i, row in enumerate(grid) if 1 in row), -1)
        
        # If no row with a 1, the grid is already valid
        if row_with_one == -1:
            return 0
        
        # Initialize the count of swaps and the row with the most 1s
        swaps = 0
        max_ones_row = row_with_one
        
        # Iterate through the columns in reverse order
        for col in range(len(grid[0]) - 1, 0, -1):
            # Count the number of 1s in the current column
            ones_in_col = sum(row[col] for row in grid)
            
            # If the current column has more 1s than the max ones in the current row,
            # update the max ones row and the count of swaps
            if ones_in_col > max_ones_row:
                max_ones_row = ones_in_col
                swaps += row_with_one - max_ones_row
        
        return swaps
        