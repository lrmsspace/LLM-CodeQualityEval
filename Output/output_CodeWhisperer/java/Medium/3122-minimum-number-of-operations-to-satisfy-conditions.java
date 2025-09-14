/*
 You are given a 2D matrix grid of size m x n. In one operation, you can change the value of any cell to any non-negative number. You need to perform some operations such that each cell grid[i][j] is:
 Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it exists).
 Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if it exists).
 Return the minimum number of operations needed.
 Example 1:
 Input: grid = [[1,0,2],[1,0,2]]
 Output: 0
 Explanation:
 All the cells in the matrix already satisfy the properties.
 Example 2:
 Input: grid = [[1,1,1],[0,0,0]]
 Output: 3
 Explanation:
 The matrix becomes [[1,0,1],[1,0,1]] which satisfies the properties, by doing these 3 operations:
 Change grid[1][0] to 1.
 Change grid[0][1] to 0.
 Change grid[1][2] to 1.
 Example 3:
 Input: grid = [[1],[2],[3]]
 Output: 2
 Explanation:
 There is a single column. We can change the value to 1 in each cell using 2 operations.
 Constraints:
 1 <= n, m <= 1000
 0 <= grid[i][j] <= 9
*/

class Solution {
    public int minimumOperations(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[n][10];
        for (int i = m - 1; i >= 0; i--) {
            int[] cnt = new int[10];
            for (int j = 0; j < n; j++) {
                cnt[grid[i][j]]++;
            }
            for (int j = 0; j < 10; j++) {
                int max = 0;
                for (int k = 0; k < 10; k++) {
                    if (k != j) {
                        max = Math.max(max, dp[n - 1][k]);
                    }
                }
                dp[n - 1][j] = m - cnt[j] + max;
            }
            for (int j = n - 2; j >= 0; j--) {
                int[] cnt2 = new int[10];
                for (int k = 0; k < m; k++) {
                    cnt2[grid[k][j]]++;
                }
                for (int k = 0; k < 10; k++) {
                    int max = 0;
                    for (int l = 0; l < 10; l++) {
                        if (l != k) {
                            max = Math.max(max, dp[j + 1][l]);
                        }
                    }
                    dp[j][k] = n - cnt2[k] + max;
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < 10; i++) {
            ans = Math.min(ans, dp[0][i]);
        }
        return ans;
                
    }
}