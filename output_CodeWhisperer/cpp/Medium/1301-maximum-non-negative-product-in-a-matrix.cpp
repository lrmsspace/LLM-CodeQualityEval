/**https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/ */
//You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.
//Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.
//Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.
//Notice that the modulo is performed after getting the maximum product.
// 
//Example 1:
//Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
//Output: -1
//Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
//Example 2:
//Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
//Output: 8
//Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).
//Example 3:
//Input: grid = [[1,3],[0,-4]]
//Output: 0
//Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 15
//	-4 <= grid[i][j] <= 4
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long>> max_dp(m, vector<long>(n, 0));
        vector<vector<long>> min_dp(m, vector<long>(n, 0));
        max_dp[0][0] = min_dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            max_dp[i][0] = min_dp[i][0] = max_dp[i - 1][0] * grid[i][0];
            min_dp[i][0] = min_dp[i - 1][0] * grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            max_dp[0][j] = min_dp[0][j] = max_dp[0][j - 1] * grid[0][j];
            min_dp[0][j] = min_dp[0][j - 1] * grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    max_dp[i][j] = max(max_dp[i - 1][j], max_dp[i][j - 1]) * grid[i][j];
                    min_dp[i][j] = min(min_dp[i - 1][j], min_dp[i][j - 1]) * grid[i][j];
                } else {
                    max_dp[i][j] = min(min_dp[i - 1][j], min_dp[i][j - 1]) * grid[i][j];
                    min_dp[i][j] = max(max_dp[i - 1][j], max_dp[i][j - 1]) * grid[i][j];
                }
            }
        }
        if (max_dp[m - 1][n - 1] < 0) {
            return -1;
        } else {
            return max_dp[m - 1][n - 1] % 1000000007;
   }         
    }
};