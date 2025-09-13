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
        def isMagicSquare(subgrid):
            nums = [num for row in subgrid for num in row]
            if sorted(nums) != list(range(1, 10)):
                return False
            row_sums = [sum(row) for row in subgrid]
            col_sums = [sum(col) for col in zip(*subgrid)]
            diag_sums = [sum(subgrid[i][i] for i in range(3)), sum(subgrid[i][2-i] for i in range(3))]
            if len(set(row_sums + col_sums + diag_sums)) != 1:
                return False
            return True
        
        count = 0
        for i in range(len(grid) - 2):
            for j in range(len(grid[0]) - 2):
                subgrid = [row[j:j+3] for row in grid[i:i+3]]
                if isMagicSquare(subgrid):
                    count += 1
        return count

        