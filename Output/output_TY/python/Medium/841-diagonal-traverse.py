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
        m, n = len(mat), len(mat[0])
        ans = []
        for i in range(m + n - 1):
            if i % 2 == 0:
                x, y = 0, i
                while x < m and y >= 0:
                    ans.append(mat[x][y])
                    x += 1
                    y -= 1
            else:
                x, y = i, m - 1
                while x >= 0 and y < n:
                    ans.append(mat[x][y])
                    x -= 1
                    y += 1
        return ans