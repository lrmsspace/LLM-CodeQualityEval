/*
 You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:
 Each of the two resulting sections formed by the cut is non-empty.
 The sum of the elements in both sections is equal.
 Return true if such a partition exists; otherwise return false.
 Example 1:
 Input: grid = [[1,4],[2,3]]
 Output: true
 Explanation:
 A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.
 Example 2:
 Input: grid = [[1,3],[2,4]]
 Output: false
 Explanation:
 No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.
 Constraints:
 1 <= m == grid.length <= 105
 1 <= n == grid[i].length <= 105
 2 <= m * n <= 105
 1 <= grid[i][j] <= 105
*/

class Solution {
    public boolean canPartitionGrid(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        boolean[][] dp = new boolean[m + 1][target + 1];
        dp[0][0] = true;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];
                for (int k = 1; k <= n && k <= j; k++) {
                    dp[i][j] |= dp[i - 1][j - k] && (j - k + grid[i - 1][k - 1] * 2 <= target);
                }
            }
        }
        return dp[m][target];
            
    }
}