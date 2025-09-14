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
        m = len(grid)
        n = len(grid[0])
        total_sum = sum(sum(row) for row in grid)
        if total_sum % 2 != 0:
            return False
        target_sum = total_sum / 2
        dp = [[False] * (target_sum + 1) for _ in range(m + 1)]
        dp[0][0] = True
        for i in range(1, m + 1):
            for j in range(target_sum + 1):
                if j >= sum(grid[i - 1]):
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - grid[i - 1][0]]
                else:
                    dp[i][j] = dp[i - 1][j]
        return dp[m][target_sum]        