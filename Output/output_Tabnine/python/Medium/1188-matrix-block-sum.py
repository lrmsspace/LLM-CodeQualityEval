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
        prefix_sum = [[0] * (n+1) for _ in range(m+1)]
        
        for i in range(1, m+1):
            for j in range(1, n+1):
                prefix_sum[i][j] = mat[i-1][j-1] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1]
        
        result = [[0] * n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                left = max(0, j-k)
                right = min(n-1, j+k)
                top = max(0, i-k)
                bottom = min(m-1, i+k)
        
                result[i][j] = prefix_sum[bottom+1][right+1] - prefix_sum[top][right+1] - prefix_sum[bottom+1][left] + prefix_sum[top][left]
        return result
        