#https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
#You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.
#The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).
#Find the kth largest value (1-indexed) of all the coordinates of matrix.
# 
#Example 1:
#Input: matrix = [[5,2],[1,6]], k = 1
#Output: 7
#Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.
#Example 2:
#Input: matrix = [[5,2],[1,6]], k = 2
#Output: 5
#Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.
#Example 3:
#Input: matrix = [[5,2],[1,6]], k = 3
#Output: 4
#Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.
# 
#Constraints:
#	m == matrix.length
#	n == matrix[i].length
#	1 <= m, n <= 1000
#	0 <= matrix[i][j] <= 106
#	1 <= k <= m * n
class Solution(object):
    def kthLargestValue(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        if not matrix or not matrix[0]:
            return 0
            
        m, n = len(matrix), len(matrix[0])
        
        # Create a dp array to store XOR values
        dp = [[0] * n for _ in range(m)]
        
        # Store all XOR values in a list for finding kth largest
        values = []
        
        # Calculate XOR values for each coordinate
        for i in range(m):
            for j in range(n):
                # Current cell's value
                dp[i][j] = matrix[i][j]
                
                # XOR with left cell if exists
                if j > 0:
                    dp[i][j] ^= dp[i][j-1]
                    
                # XOR with upper cell if exists
                if i > 0:
                    dp[i][j] ^= dp[i-1][j]
                    
                # XOR with diagonal cell if exists (to avoid double XORing)
                if i > 0 and j > 0:
                    dp[i][j] ^= dp[i-1][j-1]
                
                # Add to values list
                values.append(dp[i][j])
        
        # Sort values in descending order
        values.sort(reverse=True)
        
        # Return kth largest value
        return values[k-1]
    