#https://leetcode.com/problems/sum-of-matrix-after-queries/
#You are given an integer n and a 0-indexed 2D array queries where queries[i] = [typei, indexi, vali].
#Initially, there is a 0-indexed n x n matrix filled with 0's. For each query, you must apply one of the following changes:
#	if typei == 0, set the values in the row with indexi to vali, overwriting any previous values.
#	if typei == 1, set the values in the column with indexi to vali, overwriting any previous values.
#Return the sum of integers in the matrix after all queries are applied.
# 
#Example 1:
#Input: n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
#Output: 23
#Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 23. 
#Example 2:
#Input: n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
#Output: 17
#Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 17.
# 
#Constraints:
#	1 <= n <= 104
#	1 <= queries.length <= 5 * 104
#	queries[i].length == 3
#	0 <= typei <= 1
#	0 <= indexi < n
#	0 <= vali <= 105
class Solution(object):
    def matrixSumQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: int
        """
        # Initialize the matrix with zeros
        matrix = [[0] * n for _ in range(n)]
        
        # Initialize the prefix sum array
        prefix_sum = [[0] * n for _ in range(n)]
        
        # Iterate through the queries and update the matrix and prefix sum array
        for query in queries:
            typei, indexi, vali = query
            
            # Update the matrix
            if typei == 0:
                for j in range(n):
                    matrix[indexi][j] = vali
            else:
                for i in range(n):
                    matrix[i][indexi] = vali
            
            # Update the prefix sum array
            for i in range(n):
                for j in range(n):
                    prefix_sum[i][j] = prefix_sum[i][j-1] + prefix_sum[i-1][j] - prefix_sum[i-1][j-1] + matrix[i][j]
        
        # Calculate the sum of the matrix after all queries
        total_sum = 0
        for i in range(n):
            for j in range(n):
                total_sum += prefix_sum[i][j]
        
        return total_sum
        