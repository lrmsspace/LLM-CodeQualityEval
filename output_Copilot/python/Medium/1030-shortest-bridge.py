#https://leetcode.com/problems/shortest-bridge/
#You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
#An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
#You may change 0's to 1's to connect the two islands to form one island.
#Return the smallest number of 0's you must flip to connect the two islands.
# 
#Example 1:
#Input: grid = [[0,1],[1,0]]
#Output: 1
#Example 2:
#Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
#Output: 2
#Example 3:
#Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
#Output: 1
# 
#Constraints:
#	n == grid.length == grid[i].length
#	2 <= n <= 100
#	grid[i][j] is either 0 or 1.
#	There are exactly two islands in grid.
class Solution(object):
    def shortestBridge(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # 1. DFS + BFS
        # 2. 时间复杂度O(n^2)，空间复杂度O(n^2)
        n = len(grid)
        visited = [[False] * n for _ in range(n)]
        
        def dfs(x, y):
            if x < 0 or x >= n or y < 0 or y >= n or visited[x][y] or grid[x][y] == 0:
                return
            visited[x][y] = True
            for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                dfs(x + dx, y + dy)        

        def bfs():
            queue = deque()
            for i in range(n):
                for j in range(n):
                    if visited[i][j]:
                        queue.append((i, j))
            distance = 0
            while queue:
                size = len(queue)
                for _ in range(size):
                    x, y = queue.popleft()
                    for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                        nx, ny = x + dx, y + dy
                        if nx < 0 or nx >= n or ny < 0 or ny >= n:
                            continue
                        if grid[nx][ny] == 1 and not visited[nx][ny]:
                            return distance
                        if not visited[nx][ny]:
                            visited[nx][ny] = True
                            queue.append((nx, ny))
                distance += 1
            return -1
        
        # 找到第一个岛屿并标记为已访问
        found_first_island = False
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1 and not found_first_island:
                    dfs(i, j)
                    found_first_island = True
        
        # 从第一个岛屿开始进行 BFS，寻找第二个岛屿并计算距离
        return bfs()
# Test cases       