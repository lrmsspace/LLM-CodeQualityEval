/**https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/ */
//Given a 1-indexed m x n integer matrix mat, you can select any cell in the matrix as your starting cell.
//From the starting cell, you can move to any other cell in the same row or column, but only if the value of the destination cell is strictly greater than the value of the current cell. You can repeat this process as many times as possible, moving from cell to cell until you can no longer make any moves.
//Your task is to find the maximum number of cells that you can visit in the matrix by starting from some cell.
//Return an integer denoting the maximum number of cells that can be visited.
// 
//Example 1:
//Input: mat = [[3,1],[3,4]]
//Output: 2
//Explanation: The image shows how we can visit 2 cells starting from row 1, column 2. It can be shown that we cannot visit more than 2 cells no matter where we start from, so the answer is 2. 
//Example 2:
//Input: mat = [[1,1],[1,1]]
//Output: 1
//Explanation: Since the cells must be strictly increasing, we can only visit one cell in this example. 
//Example 3:
//Input: mat = [[3,1,6],[-9,5,7]]
//Output: 4
//Explanation: The image above shows how we can visit 4 cells starting from row 2, column 1. It can be shown that we cannot visit more than 4 cells no matter where we start from, so the answer is 4. 
// 
//Constraints:
//	m == mat.length 
//	n == mat[i].length 
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	-105 <= mat[i][j] <= 105
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        vector<vector<int>> dp2(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            if (mat[i][0] > mat[i - 1][0]) {
                dp[i][0] = dp[i - 1][0] + 1;
            }
        }
        for (int j = 1; j < n; j++) {
            if (mat[0][j] > mat[0][j - 1]) {
                dp[0][j] = dp[0][j - 1] + 1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (mat[i][j] > mat[i - 1][j]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
                }
                if (mat[i][j] > mat[i][j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
        for (int i = m - 2; i >= 0; i--) {
            if (mat[i][n - 1] > mat[i + 1][n - 1]) {
                dp2[i][n - 1] = dp2[i + 1][n - 1] + 1;
            }
        }
        for (int j = n - 2; j >= 0; j--) {
            if (mat[m - 1][j] > mat[m - 1][j + 1]) {
                dp2[m - 1][j] = dp2[m - 1][j + 1] + 1;
            }
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (mat[i][j] > mat[i + 1][j]) {
                    dp2 [i][j] = max(dp2[i][j], dp2[i + 1][j] + 1);
                        }
                        if (mat[i][j] > mat[i][j + 1]) {
                            dp2[i][j] = max(dp2[i][j], dp2[i][j + 1] + 1);
                        }
                    }
                }
                int maxCells = 0;
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        maxCells = max(maxCells, dp[i][j] + dp2[i][j] - 1);
                    }
                }   
                return maxCells;
    }
};