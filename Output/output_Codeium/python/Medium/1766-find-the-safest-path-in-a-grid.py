#https://leetcode.com/problems/find-the-safest-path-in-a-grid/
#You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:
#	A cell containing a thief if grid[r][c] = 1
#	An empty cell if grid[r][c] = 0
#You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.
#The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.
#Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
#An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
#The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.
# 
#Example 1:
#Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
#Output: 0
#Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
#Example 2:
#Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
#Output: 2
#Explanation: The path depicted in the picture above has a safeness factor of 2 since:
#- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
#It can be shown that there are no other paths with a higher safeness factor.
#Example 3:
#Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
#Output: 2
#Explanation: The path depicted in the picture above has a safeness factor of 2 since:
#- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
#- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
#It can be shown that there are no other paths with a higher safeness factor.
# 
#Constraints:
#	1 <= grid.length == n <= 400
#	grid[i].length == n
#	grid[i][j] is either 0 or 1.
#	There is at least one thief in the grid.
class Solution(object):
    def maximumSafenessFactor(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int 
        """
        import heapq

        n = len(grid)
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        # Initialize the distance with infinity and set the distance for thieves to 0
        dist = [[float('inf')] * n for _ in range(n)]
        queue = []

        for r in range(n):
            for c in range(n):
                if grid[r][c] == 1:
                    dist[r][c] = 0
                    heapq.heappush(queue, (0, r, c))

        # Perform multi-source BFS to calculate minimum distance to any thief
        while queue:
            d, r, c = heapq.heappop(queue)
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n:
                    if dist[nr][nc] > d + 1:
                        dist[nr][nc] = d + 1
                        heapq.heappush(queue, (dist[nr][nc], nr, nc))

        # Binary search for the maximum safeness factor
        def canReachEnd(safeness):
            if dist[0][0] < safeness:
                return False
            visited = [[False] * n for _ in range(n)]
            stack = [(0, 0)]
            while stack:

                r, c = stack.pop()
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < n and 0 <= nc < n:
                        if not visited[nr][nc] and dist[nr][nc] < safeness:
                            visited[nr][nc] = True
                            stack.append((nr, nc))
            return visited[n - 1][n - 1]

        l, r = 0, dist[n - 1][n - 1]
        while l < r:
            mid = (l + r) // 2
            if canReachEnd(mid):
                l = mid + 1
            else:
                r = mid
        return r
