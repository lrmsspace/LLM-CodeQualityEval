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
        
        # Initialize the distance matrix with -1
        dist = [[-1] * len(grid[0]) for _ in range(len(grid))]
        
        # Initialize the queue with all cells containing thieves
        queue = []
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    queue.append((i, j))
                    dist[i][j] = 0
        
        # Perform BFS to calculate the distance from each cell to the nearest thief
        while queue:
            x, y = queue.pop(0)
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and dist[nx][ny] == -1:
                    dist[nx][ny] = dist[x][y] + 1
                    queue.append((nx, ny))
        
        # Initialize the priority queue with the top-left cell
        pq = [(-dist[0][0], 0, 0)]
        
        # Perform Dijkstra's algorithm to find the maximum safeness factor
        while pq:
            d, x, y = heapq.heappop(pq)
            d = -d
            if x == len(grid) - 1 and y == len(grid[0]) - 1:
                return d
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]):
                    nd = min(d, dist[nx][ny])
                    heapq.heappush(pq, (-nd, nx, ny))
                    dist[nx][ny] = -1
        
        return -1
