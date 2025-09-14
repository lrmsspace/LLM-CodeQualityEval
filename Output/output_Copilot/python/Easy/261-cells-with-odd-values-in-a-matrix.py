#https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
#There is an m x n matrix that is initialized to all 0's. There is also a 2D array indices where each indices[i] = [ri, ci] represents a 0-indexed location to perform some increment operations on the matrix.
#For each location indices[i], do both of the following:
#	Increment all the cells on row ri.
#	Increment all the cells on column ci.
#Given m, n, and indices, return the number of odd-valued cells in the matrix after applying the increment to all locations in indices.
# 
#Example 1:
#Input: m = 2, n = 3, indices = [[0,1],[1,1]]
#Output: 6
#Explanation: Initial matrix = [[0,0,0],[0,0,0]].
#After applying first increment it becomes [[1,2,1],[0,1,0]].
#The final matrix is [[1,3,1],[1,3,1]], which contains 6 odd numbers.
#Example 2:
#Input: m = 2, n = 2, indices = [[1,1],[0,0]]
#Output: 0
#Explanation: Final matrix = [[2,2],[2,2]]. There are no odd numbers in the final matrix.
# 
#Constraints:
#	1 <= m, n <= 50
#	1 <= indices.length <= 100
#	0 <= ri < m
#	0 <= ci < n
# 
#Follow up: Could you solve this in O(n + m + indices.length) time with only O(n + m) extra space?
class Solution(object):
    def oddCells(self, m, n, indices):
        """
        :type m: int
        :type n: int
        :type indices: List[List[int]]
        :rtype: int
        """
        # Initialize a matrix of size m x n with all elements set to 0
        matrix = [[0] * n for _ in range(m)]
        
        # Iterate through each index in indices
        for r, c in indices:
            # Increment the entire row at index r
            for j in range(n):
                matrix[r][j] += 1
            # Increment the entire column at index c
            for i in range(m):
                matrix[i][c] += 1
        
        # Count the number of odd values in the matrix
        count = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] % 2 == 1:
                    count += 1
        
        return count