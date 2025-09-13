# You are given a 0-indexed integer matrix grid and an integer k.
# Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.
# Example 1:
# Input: grid = [[7,6,3],[6,6,1]], k = 18
# Output: 4
# Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.
# Example 2:
# Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
# Output: 6
# Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.
# Constraints:
# m == grid.length 
# n == grid[i].length
# 1 <= n, m <= 1000 
# 0 <= grid[i][j] <= 1000
# 1 <= k <= 109
class Solution(object):
    def countSubmatrices(self, grid, k):
        m, n = len(grid), len(grid[0])
        prefix_sum = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1] + grid[i-1][j-1]
        
        count = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                for r in range(i, m + 1):
                    for c in range(j, n + 1):
                        submatrix_sum = prefix_sum[r][c] - prefix_sum[i-1][c] - prefix_sum[r][j-1] + prefix_sum[i-1][j-1]
                        if submatrix_sum <= k:
                            count += 1
        
        return count