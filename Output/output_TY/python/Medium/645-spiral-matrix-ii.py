#https://leetcode.com/problems/spiral-matrix-ii/
#Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
# 
#Example 1:
#Input: n = 3
#Output: [[1,2,3],[8,9,4],[7,6,5]]
#Example 2:
#Input: n = 1
#Output: [[1]]
# 
#Constraints:
#	1 <= n <= 20
class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        matrix = [[0 for i in range(n)] for j in range(n)]
        
        row_start = 0
        row_end = n-1
        col_start = 0
        col_end = n-1
        
        num = 1
        
        while row_start <= row_end and col_start <= col_end:
            for i in range(col_start, col_end+1):
                matrix[row_start][i] = num
                num += 1
            row_start += 1
            
            for i in range(row_start, row_end+1):
                matrix[i][col_end] = num
                num += 1
            col_end -= 1
        
        if row_start <= row_end:
            for i in range(col_end, col_start-1, -1):
                matrix[row_end][i] = num
                num += 1
            row_end -= 1
        
        if col_start <= col_end:
            for i in range(row_end, row_start-1, -1):
                matrix[i][col_start] = num
                num += 1
            col_start += 1
            
 
        return matrix