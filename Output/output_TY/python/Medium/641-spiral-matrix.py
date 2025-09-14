#https://leetcode.com/problems/spiral-matrix/
#Given an m x n matrix, return all elements of the matrix in spiral order.
# 
#Example 1:
#Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
#Output: [1,2,3,6,9,8,7,4,5]
#Example 2:
#Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
#Output: [1,2,3,4,8,12,11,10,9,5,6,7]
# 
#Constraints:
#	m == matrix.length
#	n == matrix[i].length
#	1 <= m, n <= 10
#	-100 <= matrix[i][j] <= 100
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        row, col = len(matrix), len(matrix[0])
        res = []
        while row > 0 and col > 0:
            for i in range(col):
                res.append(matrix[0][i])
            row -= 1
            for i in range(1, row):
                res.append(matrix[i][col-1])
            col -= 1
            if row == 0 or col == 0:
                break
            for i in range(col-1, -1, -1):
                res.append(matrix[row][i])
            row -= 1
            for i in range(row, 0, -1):
                res.append(matrix[i][0])
            col -= 1
        return res