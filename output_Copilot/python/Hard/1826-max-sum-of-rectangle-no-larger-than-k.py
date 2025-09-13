#https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
#Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
#It is guaranteed that there will be a rectangle with a sum no larger than k.
# 
#Example 1:
#Input: matrix = [[1,0,1],[0,-2,3]], k = 2
#Output: 2
#Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
#Example 2:
#Input: matrix = [[2,2,-1]], k = 3
#Output: 3
# 
#Constraints:
#	m == matrix.length
#	n == matrix[i].length
#	1 <= m, n <= 100
#	-100 <= matrix[i][j] <= 100
#	-105 <= k <= 105
# 
#Follow up: What if the number of rows is much larger than the number of columns?
class Solution(object):
    def maxSumSubmatrix(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        import bisect
        from sortedcontainers import SortedList

        def maxSumSubarray(arr, k):
            max_sum = float('-inf')
            curr_sum = 0
            prefix_sums = SortedList([0])

            for num in arr:
                curr_sum += num
                idx = prefix_sums.bisect_left(curr_sum - k)
                if idx < len(prefix_sums):
                    max_sum = max(max_sum, curr_sum - prefix_sums[idx])
                prefix_sums.add(curr_sum)

            return max_sum

        m, n = len(matrix), len(matrix[0])
        result = float('-inf')

        for left in range(n):
            row_sum = [0] * m
            for right in range(left, n):
                for i in range(m):
                    row_sum[i] += matrix[i][right]
                result = max(result, maxSumSubarray(row_sum, k))

        return result        