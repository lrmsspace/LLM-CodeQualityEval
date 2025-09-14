#https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
#Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.
# 
#Example 1:
#Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
#Output: 2
#Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
#Example 2:
#Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
#Output: 0
# 
#Constraints:
#	m == mat.length
#	n == mat[i].length
#	1 <= m, n <= 300
#	0 <= mat[i][j] <= 104
#	0 <= threshold <= 105
class Solution(object):
    def maxSideLength(self, mat, threshold):
        """
        :type mat: List[List[int]]
        :type threshold: int
        :rtype: int
        """
        m, n = len(mat), len(mat[0])
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1]
        
        max_side_length = 0
        
        for side_length in range(1, min(m, n) + 1):
            for i in range(1, m - side_length + 1):
                j = i + side_length - 1
                square_sum = dp[i + side_length][j + side_length] - dp[i - 1][j + side_length] - dp[i + side_length][j - 1] + dp[i - 1][j - 1]
            if square_sum <= threshold:
                max_side_length = side_length
        
        return max_side_length
        