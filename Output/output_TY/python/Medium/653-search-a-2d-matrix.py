#https://leetcode.com/problems/search-a-2d-matrix/
#You are given an m x n integer matrix matrix with the following two properties:
#	Each row is sorted in non-decreasing order.
#	The first integer of each row is greater than the last integer of the previous row.
#Given an integer target, return true if target is in matrix or false otherwise.
#You must write a solution in O(log(m * n)) time complexity.
# 
#Example 1:
#Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
#Output: true
#Example 2:
#Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
#Output: false
# 
#Constraints:
#	m == matrix.length
#	n == matrix[i].length
#	1 <= m, n <= 100
#	-104 <= matrix[i][j], target <= 104
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        row = len(matrix)
        col = len(matrix[0])
        i = 0
        j = col - 1
        while i < row and j >= 0:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                j -= 1
            else:
                i += 1
        return False