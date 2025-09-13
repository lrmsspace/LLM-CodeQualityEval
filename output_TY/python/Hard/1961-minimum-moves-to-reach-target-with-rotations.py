#https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/
#In an n*n grid, there is a snake that spans 2 cells and starts moving from the top left corner at (0, 0) and (0, 1). The grid has empty cells represented by zeros and blocked cells represented by ones. The snake wants to reach the lower right corner at (n-1, n-2) and (n-1, n-1).
#In one move the snake can:
#	Move one cell to the right if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
#	Move down one cell if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
#	Rotate clockwise if it's in a horizontal position and the two cells under it are both empty. In that case the snake moves from (r, c) and (r, c+1) to (r, c) and (r+1, c).
#	
#	Rotate counterclockwise if it's in a vertical position and the two cells to its right are both empty. In that case the snake moves from (r, c) and (r+1, c) to (r, c) and (r, c+1).
#	
#Return the minimum number of moves to reach the target.
#If there is no way to reach the target, return -1.
# 
#Example 1:
#Input: grid = [[0,0,0,0,0,1],
#               [1,1,0,0,1,0],
#               [0,0,0,0,1,1],
#               [0,0,1,0,1,0],
#               [0,1,1,0,0,0],
#               [0,1,1,0,0,0]]
#Output: 11
#Explanation:
#One possible solution is [right, right, rotate clockwise, right, down, down, down, down, rotate counterclockwise, right, down].
#Example 2:
#Input: grid = [[0,0,1,1,1,1],
#               [0,0,0,0,1,1],
#               [1,1,0,0,0,1],
#               [1,1,1,0,0,1],
#               [1,1,1,0,0,1],
#               [1,1,1,0,0,0]]
#Output: 9
# 
#Constraints:
#	2 <= n <= 100
#	0 <= grid[i][j] <= 1
#	It is guaranteed that the snake starts at empty cells.
class Solution(object):
    def minimumMoves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        dp = [[[float('inf')] * 2 for _ in range(n)] for _ in range(n)]
        dp[0][1][0] = 1
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1: continue
                for k in range(2):
                    for l in range(2):
                        if dp[i][j][k] == float('inf'): continue
                        if j + 1 < n and grid[i][j + 1] == 0 and dp[i][j + 1][k] > dp[i][j][k]:
                            dp[i][j + 1][k] = dp[i][j][k]
                        if i + 1 < n and grid[i + 1][j] ==0 and dp[i + 1][j][k] > dp[i][j][k]:
                            dp[i + 1][j][k] = dp[i][j][k]
                        if k == 0 and j + 2 < n and grid[i][j + 2] == 0 and grid[i + 1][j + 1] == 0 and dp[i][j + 2][1] > dp[i][j][k] + 1:
                            dp[i][j + 2][1] = dp[i][j][k] + 1
                        if k == 1 and i + 2 < n and grid[i + 2][j] == 0 and grid[i + 1][j + 1] == 0 and dp[i + 2][j][0] > dp[i][j][k] + 1: 
                            dp[i + 2][j][0] = dp[i][j][k] + 1
        return min(dp[n - 1][n - 2][0], dp[n - 1][n - 2][1]) if dp[n - 1][n - 2][0] != float('inf') or dp[n - 1][n - 2][1] != float('inf') else -1