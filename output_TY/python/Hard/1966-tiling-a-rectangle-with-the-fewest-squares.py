#https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/
#Given a rectangle of size n x m, return the minimum number of integer-sided squares that tile the rectangle.
# 
#Example 1:
#Input: n = 2, m = 3
#Output: 3
#Explanation: 3 squares are necessary to cover the rectangle.
#2 (squares of 1x1)
#1 (square of 2x2)
#Example 2:
#Input: n = 5, m = 8
#Output: 5
#Example 3:
#Input: n = 11, m = 13
#Output: 6
# 
#Constraints:
#	1 <= n, m <= 13
class Solution(object):
    def tilingRectangle(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """

        def dfs(i, j, k):
            if i == n and j == m: return 0
            if k >= ans: return inf
            ans = min(ans, k)
            for x in range(i, n):
                for y in range(j, m):
                    if grid[x][y] == 0:
                        for s in range(min(n - x, m - y), 0, -1):
                            if all(grid[x + i][y + j] == 0 for i in range(s)):
                                for i in range(s):
                                    for j in range(s):
                                        grid[x + i][y + j] = 1
                                dfs(x, y + s, k + 1)
                                for i in range(s):
                                    for j in range(s):
                                        grid[x + i][y + j] = 0
        ans = inf
        grid = [[0] * m for _ in range(n)]
        dfs(0, 0, 0)
        return ans
                                    
