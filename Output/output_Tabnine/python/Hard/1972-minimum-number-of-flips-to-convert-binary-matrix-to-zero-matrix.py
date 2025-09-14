#https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/
#Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighbors if they share one edge.
#Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.
#A binary matrix is a matrix with all cells equal to 0 or 1 only.
#A zero matrix is a matrix with all cells equal to 0.
# 
#Example 1:
#Input: mat = [[0,0],[0,1]]
#Output: 3
#Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
#Example 2:
#Input: mat = [[0]]
#Output: 0
#Explanation: Given matrix is a zero matrix. We do not need to change it.
#Example 3:
#Input: mat = [[1,0,0],[1,0,0]]
#Output: -1
#Explanation: Given matrix cannot be a zero matrix.
# 
#Constraints:
#	m == mat.length
#	n == mat[i].length
#	1 <= m, n <= 3
#	mat[i][j] is either 0 or 1.
class Solution(object):
    def minFlips(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        def count_ones(row):
            return row.count(1)
        
        m, n = len(mat), len(mat[0])
        ones_count = sum(count_ones(row) for row in mat)
        
        if ones_count == 0:
            return 0
        
        if ones_count % 2 == 1:
            return -1
        
        flip_count = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1:
                    flip_count += 1
                    if j < n - 1:
                        mat[i][j+1] ^= 1
                    if i < m - 1:
                        mat[i+1][j] ^= 1
                    if i > 0:
                        mat[i-1][j] ^= 1
                    if j > 0:
                        mat[i][j-1] ^= 1
        
        return flip_count
        