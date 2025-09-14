#https://leetcode.com/problems/maximum-matrix-sum/
#You are given an n x n integer matrix. You can do the following operation any number of times:
#	Choose any two adjacent elements of matrix and multiply each of them by -1.
#Two elements are considered adjacent if and only if they share a border.
#Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
# 
#Example 1:
#Input: matrix = [[1,-1],[-1,1]]
#Output: 4
#Explanation: We can follow the following steps to reach sum equals 4:
#- Multiply the 2 elements in the first row by -1.
#- Multiply the 2 elements in the first column by -1.
#Example 2:
#Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
#Output: 16
#Explanation: We can follow the following step to reach sum equals 16:
#- Multiply the 2 last elements in the second row by -1.
# 
#Constraints:
#	n == matrix.length == matrix[i].length
#	2 <= n <= 250
#	-105 <= matrix[i][j] <= 105
class Solution(object):
    def maxMatrixSum(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        sum_val = 0
        negative_count = 0
        for row in matrix:
            for val in row:
                sum_val += val
                if val < 0:
                    negative_count += 1
        if negative_count % 2 == 1:
            min_val = min(min(row) for row in matrix)
            sum_val -= 2 * min_val
        return sum_val
