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
        res = 0
        for r in range(len(grid)-2):
            for c in range(len(grid[0])-2):
                if self.isMagic([[grid[r][c],grid[r][c+1],grid[r][c+2]],
                                 [grid[r+1][c],grid[r+1][c+1],grid[r+1][c+2]],
                                 [grid[r+2][c],grid[r+2][c+1],grid[r+2][c+2]]]):
                    res += 1
        return res
    
    def isMagic(self, grid):
        s = sum(grid[0])
        for row in grid:
            if sum(row) != s:
                return False
        for col in range(len(grid[0])):
            if sum(grid[i][col] for i in range(len(grid))) != s:
                return False
        if sum(grid[i][i] for i in range(len(grid))) != s:
            return False
        if sum(grid[i][len(grid)-i-1] for i in range(len(grid))) != s:
            return False
        return True
