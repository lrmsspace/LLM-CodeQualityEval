#https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/
#Given the following details of a matrix with n columns and 2 rows :
#	The matrix is a binary matrix, which means each element in the matrix can be 0 or 1.
#	The sum of elements of the 0-th(upper) row is given as upper.
#	The sum of elements of the 1-st(lower) row is given as lower.
#	The sum of elements in the i-th column(0-indexed) is colsum[i], where colsum is given as an integer array with length n.
#Your task is to reconstruct the matrix with upper, lower and colsum.
#Return it as a 2-D integer array.
#If there are more than one valid solution, any of them will be accepted.
#If no valid solution exists, return an empty 2-D array.
# 
#Example 1:
#Input: upper = 2, lower = 1, colsum = [1,1,1]
#Output: [[1,1,0],[0,0,1]]
#Explanation: [[1,0,1],[0,1,0]], and [[0,1,1],[1,0,0]] are also correct answers.
#Example 2:
#Input: upper = 2, lower = 3, colsum = [2,2,1,1]
#Output: []
#Example 3:
#Input: upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
#Output: [[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
# 
#Constraints:
#	1 <= colsum.length <= 10^5
#	0 <= upper, lower <= colsum.length
#	0 <= colsum[i] <= 2
class Solution(object):
    def reconstructMatrix(self, upper, lower, colsum):
        """
        :type upper: int
        :type lower: int
        :type colsum: List[int]
        :rtype: List[List[int]]
        """
        # Initialize the matrix with zeros
        matrix = [[0] * len(colsum) for _ in range(2)]
        
        # Initialize the sum of rows to zero
        row_sum = [0, 0]
        
        # Iterate over the columns and sum up the elements in each row
        for i in range(len(colsum)):
            matrix[0][i] = colsum[i]
            row_sum[0] += colsum[i]
        
        # Calculate the remaining sum to be added to the lower row
        remaining_sum = upper - row_sum[0]
        
        # If the remaining sum is negative, no solution exists
        if remaining_sum < 0:
            return []
        
        # Add the remaining sum to the lower row
        matrix[1][0] = remaining_sum
        
        # If the lower row sum is still not equal to lower, no solution exists
        if row_sum[1]!= lower:
            return []
        
        # Return the reconstructed matrix
        return matrix
        