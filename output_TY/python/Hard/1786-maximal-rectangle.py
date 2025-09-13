#https://leetcode.com/problems/maximal-rectangle/
#Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
# 
#Example 1:
#Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
#Output: 6
#Explanation: The maximal rectangle is shown in the above picture.
#Example 2:
#Input: matrix = [["0"]]
#Output: 0
#Example 3:
#Input: matrix = [["1"]]
#Output: 1
# 
#Constraints:
#	rows == matrix.length
#	cols == matrix[i].length
#	1 <= row, cols <= 200
#	matrix[i][j] is '0' or '1'.
class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix or not matrix[0]: return 0
        m, n = len(matrix), len(matrix[0])
        heights = [0] * (n + 1)
        res = 0
        for i in range(m):
            for j in range(n):
                heights[j] = heights[j] + 1 if matrix[i][j] == "1" else 0
            stack = [-1]
            for k in range(n + 1):
                while heights[k] < heights[stack[-1]]:
                    h = heights[stack.pop()]
                    w = k - stack[-1] - 1
                    res = max(res, h * w)
                stack.append(k)
        return res