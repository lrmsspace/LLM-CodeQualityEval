#https://leetcode.com/problems/01-matrix/
#Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
#The distance between two adjacent cells is 1.
# 
#Example 1:
#Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
#Output: [[0,0,0],[0,1,0],[0,0,0]]
#Example 2:
#Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
#Output: [[0,0,0],[0,1,0],[1,2,1]]
# 
#Constraints:
#	m == mat.length
#	n == mat[i].length
#	1 <= m, n <= 104
#	1 <= m * n <= 104
#	mat[i][j] is either 0 or 1.
#	There is at least one 0 in mat.
class Solution(object):
    def updateMatrix(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n = len(mat), len(mat[0])
        dist = [[float('inf')] * n for _ in range(m)]
        queue = []
        
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    dist[i][j] = 0
                    queue.append((i, j))
        
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        while queue:
            x, y = queue.pop(0)
            
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                
                if 0 <= nx < m and 0 <= ny < n and dist[nx][ny] > dist[x][y] + 1:
                    dist[nx][ny] = dist[x][y] + 1
                    queue.append((nx, ny))
        
        return dist
        