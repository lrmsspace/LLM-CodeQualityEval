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
        if not matrix:
            return 0

        def maximalRectangleInHistogram(heights):
            heights.append(0)
            stack = []
            max_area = 0
            for i in range(len(heights)):
                while stack and heights[stack[-1]] > heights[i]:
                    h = heights[stack.pop()]
                    w = i if not stack else i - stack[-1] - 1
                    max_area = max(max_area, h * w)
                stack.append(i)
            return max_area

        max_area = 0
        heights = [0] * len(matrix[0])
        for row in matrix:
            for i in range(len(row)):
                if row[i] == '1':
                    heights[i] += 1
                else:
                    heights[i] = 0
            max_area = max(max_area, maximalRectangleInHistogram(heights))
        return max_area
