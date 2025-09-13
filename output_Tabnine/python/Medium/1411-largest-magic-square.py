#https://leetcode.com/problems/largest-magic-square/
#A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.
#Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.
# 
#Example 1:
#Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
#Output: 3
#Explanation: The largest magic square has a size of 3.
#Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
#- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
#- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
#- Diagonal sums: 5+4+3 = 6+4+2 = 12
#Example 2:
#Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
#Output: 2
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 50
#	1 <= grid[i][j] <= 106
class Solution(object):
    def largestMagicSquare(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def is_magic_square(subgrid):
            size = len(subgrid)
            row_sums = [sum(row) for row in subgrid]
            col_sums = [sum(col) for col in zip(*subgrid)]
            diag_sum = sum(subgrid[i][i] for i in range(size))
            anti_diag_sum = sum(subgrid[i][size - 1 - i] for i in range(size))
            return all(row_sums == col_sums == diag_sum == anti_diag_sum)
        
        def search(size):
            for i in range(len(grid) - size + 1):
                for j in range(len(grid[0]) - size + 1):
                    subgrid = [grid[i + r][j:j + size] for r in range(size)]
                    if is_magic_square(subgrid):
                        return size
            return 0
        
        max_size = 0
        for size in range(1, min(len(grid), len(grid[0])) + 1):
            max_size = max(max_size, search(size))
        return max_size