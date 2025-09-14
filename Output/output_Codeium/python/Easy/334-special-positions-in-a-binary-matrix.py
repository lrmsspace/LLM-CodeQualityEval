#https://leetcode.com/problems/special-positions-in-a-binary-matrix/
#Given an m x n binary matrix mat, return the number of special positions in mat.
#A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).
# 
#Example 1:
#Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
#Output: 1
#Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
#Example 2:
#Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
#Output: 3
#Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
# 
#Constraints:
#	m == mat.length
#	n == mat[i].length
#	1 <= m, n <= 100
#	mat[i][j] is either 0 or 1.
class Solution(object):
    def numSpecial(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        m, n = len(mat), len(mat[0])
        row_sum = [sum(row) for row in mat]
        col_sum = [sum(mat[i][j] for i in range(m)) for j in range(n)]
        
        count = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1 and row_sum[i] == 1 and col_sum[j] == 1:
                    count += 1
        
        return count

