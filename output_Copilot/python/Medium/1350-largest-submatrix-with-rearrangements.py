#https://leetcode.com/problems/largest-submatrix-with-rearrangements/
#You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
#Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.
# 
#Example 1:
#Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
#Output: 4
#Explanation: You can rearrange the columns as shown above.
#The largest submatrix of 1s, in bold, has an area of 4.
#Example 2:
#Input: matrix = [[1,0,1,0,1]]
#Output: 3
#Explanation: You can rearrange the columns as shown above.
#The largest submatrix of 1s, in bold, has an area of 3.
#Example 3:
#Input: matrix = [[1,1,0],[1,0,1]]
#Output: 2
#Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
# 
#Constraints:
#	m == matrix.length
#	n == matrix[i].length
#	1 <= m * n <= 105
#	matrix[i][j] is either 0 or 1.
class Solution(object):
    def largestSubmatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if not matrix:
            return 0
        m, n = len(matrix), len(matrix[0])
        heights = [[0] * n for _ in range(m)]
        for j in range(n):
            for i in range(m):
                if matrix[i][j] == 1:
                    heights[i][j] = heights[i - 1][j] + 1 if i > 0 else 1
                else:
                    heights[i][j] = 0
        max_area = 0
        for i in range(m):
            sorted_heights = sorted(heights[i], reverse=True)
            for j in range(n):
                max_area = max(max_area, sorted_heights[j] * (j + 1))
        return max_area        