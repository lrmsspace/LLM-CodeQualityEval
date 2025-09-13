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
        dist = [[float('inf') for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    dist[i][j] = 0
                else:
                    if i > 0:
                        dist[i][j] = min(dist[i][j], dist[i-1][j] + 1)
                    if j > 0:
                        dist[i][j] = min(dist[i][j], dist[i][j-1] + 1)
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if mat[i][j] == 0:
                    dist[i][j] = 0
                else:
                    if i < m-1:
                        dist[i][j] = min(dist[i][j], dist[i+1][j] + 1)
                    if j < n-1:
                        dist[i][j] = min(dist[i][j], dist[i][j+1] + 1)
        return dist
        