# You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:
# Each of the two resulting sections formed by the cut is non-empty.
# The sum of the elements in both sections is equal.
# Return true if such a partition exists; otherwise return false.
# Example 1:
# Input: grid = [[1,4],[2,3]]
# Output: true
# Explanation:
# A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.
# Example 2:
# Input: grid = [[1,3],[2,4]]
# Output: false
# Explanation:
# No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.
# Constraints:
# 1 <= m == grid.length <= 105
# 1 <= n == grid[i].length <= 105
# 2 <= m * n <= 105
# 1 <= grid[i][j] <= 105

class Solution(object):
    def canPartitionGrid(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        m, n = len(grid), len(grid[0])
        total_sum = sum(sum(row) for row in grid)
        if total_sum % 2 != 0:
            return False
        target = total_sum // 2

        # Check for horizontal cuts
        row_sum = 0
        for i in range(m - 1):
            row_sum += sum(grid[i])
            if row_sum == target:
                return True

        # Check for vertical cuts
        col_sum = [0] * n
        for j in range(n):
            for i in range(m):
                col_sum[j] += grid[i][j]
        for j in range(n - 1):
            col_sum[j] += col_sum[j + 1]
            if col_sum[j] == target:
                return True

        return False