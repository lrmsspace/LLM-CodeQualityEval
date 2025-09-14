#https://leetcode.com/problems/strange-printer-ii/
#There is a strange printer with the following two special requirements:
#	On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
#	Once the printer has used a color for the above operation, the same color cannot be used again.
#You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.
#Return true if it is possible to print the matrix targetGrid, otherwise, return false.
# 
#Example 1:
#Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
#Output: true
#Example 2:
#Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
#Output: true
#Example 3:
#Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
#Output: false
#Explanation: It is impossible to form targetGrid because it is not allowed to print the same color in different turns.
# 
#Constraints:
#	m == targetGrid.length
#	n == targetGrid[i].length
#	1 <= m, n <= 60
#	1 <= targetGrid[row][col] <= 60
class Solution(object):
    def isPrintable(self, targetGrid):
        """
        :type targetGrid: List[List[int]]
        :rtype: bool
        """
        m, n = len(targetGrid), len(targetGrid[0])
        for i in range(m):
            for j in range(n):
                if targetGrid[i][j] == 0:
                    return False
        for color in range(61):
            x1, y1, x2, y2 = m, n, 0, 0
            for i in range(m):
                for j in range(n):
                    if targetGrid[i][j] == color:
                        x1 = min(x1, i)
                        y1 = min(y1, j)
                        x2 = max(x2, i)
                        y2 = max(y2, j)
            if x1 == m: continue
            for i in range(x1, x2 + 1):
                for j in range(y1, y2 + 1):
                    if targetGrid[i][j] != color:
                        return False
        return True