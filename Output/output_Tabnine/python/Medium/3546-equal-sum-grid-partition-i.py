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
        # Calculate the total sum of the grid
        total_sum = sum(sum(row) for row in grid)
        
        # If the total sum is odd, it cannot be partitioned into two equal sums
        if total_sum % 2!= 0:
            return False
        
        # Calculate the target sum for each section
        target_sum = total_sum // 2
        
        # Create a 2D dp array to store the results of subproblems
        dp = [[False] * (target_sum + 1) for _ in range(len(grid) + 1)]
        
        # Initialize the first row and column of the dp array
        for i in range(len(grid) + 1):
            dp[i][0] = True
        
        for j in range(target_sum + 1):
            dp[0][j] = False
        
        # Fill the dp array using the given conditions  
        for i in range(1, len(grid) + 1):
            for j in range(1, target_sum + 1):
                dp[i][j] = dp[i - 1][j] or (dp[i - 1][j - grid[i - 1][0]] and grid[i - 1][0] + grid[i - 1][j - grid[i - 1][0]] == target_sum)
        
        # Return the result of the last cell of the dp array
        return dp[-1][-1]
        