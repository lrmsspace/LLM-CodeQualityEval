# You are given a 2D matrix grid of size 3 x 3 consisting only of characters 'B' and 'W'. Character 'W' represents the white color, and character 'B' represents the black color.
# Your task is to change the color of at most one cell so that the matrix has a 2 x 2 square where all cells are of the same color.
# Return true if it is possible to create a 2 x 2 square of the same color, otherwise, return false.
# Example 1:
# Input: grid = [["B","W","B"],["B","W","W"],["B","W","B"]]
# Output: true
# Explanation:
# It can be done by changing the color of the grid[0][2].
# Example 2:
# Input: grid = [["B","W","B"],["W","B","W"],["B","W","B"]]
# Output: false
# Explanation:
# It cannot be done by changing at most one cell.
# Example 3:
# Input: grid = [["B","W","B"],["B","W","W"],["B","W","W"]]
# Output: true
# Explanation:
# The grid already contains a 2 x 2 square of the same color.
# Constraints:
# grid.length == 3
# grid[i].length == 3
# grid[i][j] is either 'W' or 'B'.

class Solution(object):
    def canMakeSquare(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: bool
        """
        # Count the number of 'W' and 'B' characters in the grid
        count_W = sum(row.count('W') for row in grid)
        count_B = sum(row.count('B') for row in grid)
        
        # Check if the grid can be divided into two 2 x 2 squares of the same color
        if count_W % 4!= 0 or count_B % 4!= 0:
            return False
        
        # Calculate the side length of the 2 x 2 squares
        side_length = count_W // 4
        
        # Check if the grid can be divided into two 2 x 2 squares of the same color
        for i in range(0, 3 - side_length + 1):
            for j in range(0, 3 - side_length + 1):
                if self.is_square(grid, i, j, side_length):
                    return True
                return False
            
            
        