#https://leetcode.com/problems/matrix-block-sum/
#Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
#	i - k <= r <= i + k,
#	j - k <= c <= j + k, and
#	(r, c) is a valid position in the matrix.
# 
#Example 1:
#Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
#Output: [[12,21,16],[27,45,33],[24,39,28]]
#Example 2:
#Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
#Output: [[45,45,45],[45,45,45],[45,45,45]]
# 
#Constraints:
#	m == mat.length
#	n == mat[i].length
#	1 <= m, n, k <= 100
#	1 <= mat[i][j] <= 100
class Solution(object):
    def matrixBlockSum(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        m, n = len(mat), len(mat[0])
        sum_mat = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                sum_mat[i][j] = sum_mat[i - 1][j] + sum_mat[i][j - 1] - sum_mat[i - 1][j - 1] + mat[i - 1][j - 1]
        res = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                x1, y1 = max(0, i - k), max(0, j - k)
                x2, y2 = min(m, i + k +1), min(n, j + k + 1)
                res[i][j] = sum_mat[x2][y2] - sum_mat[x1][y2] - sum_mat[x2][y1] + sum_mat[x1][y1]
        return res 