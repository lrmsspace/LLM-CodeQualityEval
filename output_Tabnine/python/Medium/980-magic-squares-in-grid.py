#https://leetcode.com/problems/magic-squares-in-grid/
#A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
#Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?
#Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.
# 
#Example 1:
#Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
#Output: 1
#Explanation: 
#The following subgrid is a 3 x 3 magic square:
#while this one is not:
#In total, there is only one magic square inside the given grid.
#Example 2:
#Input: grid = [[8]]
#Output: 0
# 
#Constraints:
#	row == grid.length
#	col == grid[i].length
#	1 <= row, col <= 10
#	0 <= grid[i][j] <= 15
class Solution(object):
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def isMagic(grid):
            # Check if the grid is a magic square
            rows = [sum(row) for row in grid]
            cols = [sum(grid[i][j] for i in range(3)) for j in range(3)]
            diag1 = sum(grid[i][i] for i in range(3))
            diag2 = sum(grid[i][2-i] for i in range(3))
            return rows[0] == rows[1] == rows[2] and cols[0] == cols[1] == cols[2] and diag1 == diag2
        
        def countMagicSquares(grid, i, j):
            # Count the number of magic squares in the subgrid
            count = 0
            for x in range(i, i+3):
                for y in range(j, j+3):
                    if grid[x][y] in (1, 2, 3, 4, 5, 6, 7, 8, 9) and \
                        all(abs(grid[x][y] - num) in (0, 1, 2) for num in (grid[x-1][y-1], grid[x-1][y], grid[x-1][y+1], grid[x][y-1], grid[x][y+1], grid[x+1][y-1], grid[x+1][y], grid[x+1][y+1])):
                        count += 1
            return count
        
        rows, cols = len(grid), len(grid[0])
        count = 0
        for i in range(rows-2):
            for j in range(cols-2):
                if isMagic(grid[i:i+3, j:j+3]):
                    count += countMagicSquares(grid, i, j)
        return count    
        