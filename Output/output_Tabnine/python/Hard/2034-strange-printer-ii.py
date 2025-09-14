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
        # Initialize variables
        m, n = len(targetGrid), len(targetGrid[0])
        colors = set(range(1, m*n+1))
        rows, cols = [set() for _ in range(m)], [set() for _ in range(n)]
        
        # Find the minimum and maximum colors in each row and column
        for i in range(m):
            for j in range(n):
                colors.remove(targetGrid[i][j])
                rows[i].add(targetGrid[i][j])
                cols[j].add(targetGrid[i][j])
        
        # Helper function to check if a color can be used in a given row and column
        def isValid(color, row, col):
            return color not in rows[row] and color not in cols[col]
        
        # Helper function to perform a BFS from a given position
        def bfs(row, col):
            queue = [(row, col)]
            while queue:
                r, c = queue.pop(0)
                for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    nr, nc = r+dr, c+dc
                    if 0 <= nr < m and 0 <= nc < n and isValid(targetGrid[nr][nc], nr, nc):
                        queue.append((nr, nc))
                        colors.remove(targetGrid[nr][nc])
                        rows[nr].remove(targetGrid[nr][nc])
                        cols[nc].remove(targetGrid[nr][nc])
        
        # Perform BFS from each position in the grid
        for i in range(m):
            for j in range(n):
                bfs(i, j)
        
        return len(colors) == 0
        