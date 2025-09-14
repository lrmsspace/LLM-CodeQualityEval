#https://leetcode.com/problems/transpose-matrix/
#Given a 2D integer array matrix, return the transpose of matrix.
#The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
# 
#Example 1:
#Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
#Output: [[1,4,7],[2,5,8],[3,6,9]]
#Example 2:
#Input: matrix = [[1,2,3],[4,5,6]]
#Output: [[1,4],[2,5],[3,6]]
# 
#Constraints:
#	m == matrix.length
#	n == matrix[i].length
#	1 <= m, n <= 1000
#	1 <= m * n <= 105
#	-109 <= matrix[i][j] <= 109
class Solution(object):
    def transpose(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        # Initialize an empty list to store the transposed matrix
        transposed_matrix = [[0] * len(matrix) for _ in range(len(matrix[0]))]
        
        # Iterate over each row and column of the original matrix
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                # Set the value at the transposed matrix's current row and column to the value at the original matrix's current column and row
                transposed_matrix[j][i] = matrix[i][j]
        
        return transposed_matrix
        