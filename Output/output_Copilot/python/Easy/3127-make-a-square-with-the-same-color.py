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
        # Check all possible 2x2 squares in the 3x3 grid
        for i in range(2):
            for j in range(2):
                # Extract the 2x2 square
                square = [grid[i][j], grid[i][j+1], grid[i+1][j], grid[i+1][j+1]]
                # Count the number of 'B's and 'W's
                count_B = square.count('B')
                count_W = square.count('W')
                
                # If all are the same color or if we can change one cell to make them the same
                if count_B >= 3 or count_W >= 3:
                    return True 
        # If no valid 2x2 square found
        return False
        