# You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.
# The following proccess happens k times:
# Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.
# Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.
# Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.
# Example 1:
# Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4
# Output: false
# Explanation:
# In each step left shift is applied to rows 0 and 2 (even indices), and right shift to row 1 (odd index).
# Example 2:
# Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
# Output: true
# Explanation:
# Example 3:
# Input: mat = [[2,2],[2,2]], k = 3
# Output: true
# Explanation:
# As all the values are equal in the matrix, even after performing cyclic shifts the matrix will remain the same.
# Constraints:
# 1 <= mat.length <= 25
# 1 <= mat[i].length <= 25
# 1 <= mat[i][j] <= 25
# 1 <= k <= 50

class Solution(object):
    def areSimilar(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: bool
        """
        m, n = len(mat), len(mat[0])
        for row in range(m):
            shiftCount = k % n
            for shift in range(shiftCount):
                if row % 2 == 0: # even-indexed rows, shift left
                    firstElement = mat[row][0]
                    for col in range(n-1):
                        mat[row][col] = mat[row][col+1]
                    mat[row][n-1] = firstElement
                else: # odd-indexed rows, shift right
                    lastElement = mat[row][n-1]
                    for col in range(n-1, 0, -1):
                        mat[row][col] = mat[row][col-1]
                    mat[row][0] = lastElement
        original = [row[:] for row in mat]
        for row in range(m):
            for col in range(n):
                if mat[row][col] != original[row][col]:
                    return False
        return True

