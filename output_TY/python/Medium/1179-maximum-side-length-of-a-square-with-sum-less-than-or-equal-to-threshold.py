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
        prefix = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mat[i - 1][j - 1]
        res = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                k = min(min(i, j), m - i + 1, n - j + 1)
                while prefix[i + k - 1][j + k - 1] - prefix[i + k - 1][j - 1] - prefix[][j + k - 1] + prefix[i - 1][j + k - 1] <= threshold: k -= 1 
            res = max(res, k)
        return res