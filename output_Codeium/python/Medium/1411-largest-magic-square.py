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
        m, n = len(grid), len(grid[0])
        prefix = [[0]*(n+1) for _ in range(m+1)]
        for i in range(m):
            for j in range(n):
                prefix[i+1][j+1] = prefix[i][j+1] + prefix[i+1][j] - prefix[i][j] + grid[i][j]
        max_size = 0
        for i in range(m):
            for j in range(n):
                for size in range(1, min(m-i, n-j)+1):
                    if all(prefix[i+size][j+size] - prefix[i][j+size] - prefix[i+size][j] + prefix[i][j] == \
                           prefix[i+size-1][j+size-1] - prefix[i][j+size-1] - prefix[i+size-1][j] + prefix[i][j] for _ in range(size)):
                        max_size = max(max_size, size)
        return max_size
