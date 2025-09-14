#https://leetcode.com/problems/count-submatrices-with-all-ones/
#Given an m x n binary matrix mat, return the number of submatrices that have all ones.
# 
#Example 1:
#Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
#Output: 13
#Explanation: 
#There are 6 rectangles of side 1x1.
#There are 2 rectangles of side 1x2.
#There are 3 rectangles of side 2x1.
#There is 1 rectangle of side 2x2. 
#There is 1 rectangle of side 3x1.
#Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
#Example 2:
#Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
#Output: 24
#Explanation: 
#There are 8 rectangles of side 1x1.
#There are 5 rectangles of side 1x2.
#There are 2 rectangles of side 1x3. 
#There are 4 rectangles of side 2x1.
#There are 2 rectangles of side 2x2. 
#There are 2 rectangles of side 3x1. 
#There is 1 rectangle of side 3x2. 
#Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
# 
#Constraints:
#	1 <= m, n <= 150
#	mat[i][j] is either 0 or 1.
class Solution(object):
    def numSubmat(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        m, n = len(mat), len(mat[0])
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        res = 0
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + mat[i - 1][j - 1]
        
        for i in range(1, m + 1):
            for j in range(i, m + 1):
                for k in range(1, n + 1):
                    res += dp[j][k] - dp[i - 1][k] - dp[j][k - 1] + dp[i - 1][k - 1]
        
        return res
        