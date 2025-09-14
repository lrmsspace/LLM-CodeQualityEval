#https://leetcode.com/problems/diagonal-traverse/
#Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
# 
#Example 1:
#Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
#Output: [1,2,4,7,5,3,6,8,9]
#Example 2:
#Input: mat = [[1,2],[3,4]]
#Output: [1,2,3,4]
# 
#Constraints:
#	m == mat.length
#	n == mat[i].length
#	1 <= m, n <= 104
#	1 <= m * n <= 104
#	-105 <= mat[i][j] <= 105
class Solution(object):
    def findDiagonalOrder(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[int]
        """
        if not mat or not mat[0]:
            return []
        m, n = len(mat), len(mat[0])
        res = []
        for i in range(m + n - 1):
            if i % 2 == 0:
                for j in range(min(i, m - 1), -1, -1):
                    if i - j < n:
                        res.append(mat[j][i - j])
            else:
                for j in range(min(i, n - 1), -1, -1):
                    if i - j < m:
                        res.append(mat[i - j][j])
        return res

        