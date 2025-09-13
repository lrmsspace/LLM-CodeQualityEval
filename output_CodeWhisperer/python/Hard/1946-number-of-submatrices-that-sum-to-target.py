#https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
#Given a matrix and a target, return the number of non-empty submatrices that sum to target.
#A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
#Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.
# 
#Example 1:
#Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
#Output: 4
#Explanation: The four 1x1 submatrices that only contain 0.
#Example 2:
#Input: matrix = [[1,-1],[-1,1]], target = 0
#Output: 5
#Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
#Example 3:
#Input: matrix = [[904]], target = 0
#Output: 0
# 
#Constraints:
#	1 <= matrix.length <= 100
#	1 <= matrix[0].length <= 100
#	-1000 <= matrix[i][j] <= 1000
#	-10^8 <= target <= 10^8
class Solution(object):
    def numSubmatrixSumTarget(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: int
        """
        m, n = len(matrix), len(matrix[0])
        for row in matrix:
            for i in range(1, n):
                row[i] += row[i - 1]
        res = 0
        # sum of each row
        for i in range(n):
            for j in range(i, n):
                c = {0: 1}
                s = 0
                for k in range(m):
                    s += matrix[k][j] - (matrix[k][i - 1] if i > 0 else 0)
                    res += c.get(s - target, 0)
                    c[s] = c.get(s, 0) + 1
        return res
        