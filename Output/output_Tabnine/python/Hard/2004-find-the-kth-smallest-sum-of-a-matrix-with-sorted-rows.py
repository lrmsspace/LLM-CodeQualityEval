#https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
#You are given an m x n matrix mat that has its rows sorted in non-decreasing order and an integer k.
#You are allowed to choose exactly one element from each row to form an array.
#Return the kth smallest array sum among all possible arrays.
# 
#Example 1:
#Input: mat = [[1,3,11],[2,4,6]], k = 5
#Output: 7
#Explanation: Choosing one element from each row, the first k smallest sum are:
#[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.
#Example 2:
#Input: mat = [[1,3,11],[2,4,6]], k = 9
#Output: 17
#Example 3:
#Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
#Output: 9
#Explanation: Choosing one element from each row, the first k smallest sum are:
#[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.  
# 
#Constraints:
#	m == mat.length
#	n == mat.length[i]
#	1 <= m, n <= 40
#	1 <= mat[i][j] <= 5000
#	1 <= k <= min(200, nm)
#	mat[i] is a non-decreasing array.
class Solution(object):
    def kthSmallest(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: int
        """
        rows, cols = len(mat), len(mat[0])
        prefix_sums = [[0] * (cols + 1) for _ in range(rows + 1)]
        
        for i in range(1, rows + 1):
            for j in range(1, cols + 1):
                prefix_sums[i][j] = prefix_sums[i-1][j] + prefix_sums[i][j-1] - prefix_sums[i-1][j-1] + mat[i-1][j-1]
        
        def binary_search(target):
            left, right = 0, prefix_sums[-1][-1]
            while left < right:
                mid = (left + right) // 2
                if prefix_sums[rows][mid] < target:
                    left = mid + 1
                else:
                    right = mid
            return left
        