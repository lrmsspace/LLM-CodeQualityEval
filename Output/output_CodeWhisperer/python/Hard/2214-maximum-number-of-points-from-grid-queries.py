#https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/
#You are given an m x n integer matrix grid and an array queries of size k.
#Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:
#	If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
#	Otherwise, you do not get any points, and you end this process.
#After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
#Return the resulting array answer.
# 
#Example 1:
#Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
#Output: [5,8,1]
#Explanation: The diagrams above show which cells we visit to get points for each query.
#Example 2:
#Input: grid = [[5,2,1],[1,1,2]], queries = [3]
#Output: [0]
#Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	2 <= m, n <= 1000
#	4 <= m * n <= 105
#	k == queries.length
#	1 <= k <= 104
#	1 <= grid[i][j], queries[i] <= 106
class Solution(object):
    def maxPoints(self, grid, queries):
        """
        :type grid: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """
        m, n = len(grid), len(grid[0])
        q = sorted((v, i) for i, v in enumerate(queries))
        res = [0] * len(queries)
        heap = [(grid[0][0], 0, 0)]
        visited = {(0, 0)}
        for v, i in q:
            while heap and heap[0][0] < v:
                _, x, y = heapq.heappop(heap)
                for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and (nx, ny) not in visited:
                        visited.add((nx, ny))
                        heapq.heappush(heap, (grid[nx][ny], nx, ny))
            res[i] = len(heap)
        return res
        