/**https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ */
//Given an m x n integers matrix, return the length of the longest increasing path in matrix.
//From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
// 
//Example 1:
//Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
//Output: 4
//Explanation: The longest increasing path is [1, 2, 6, 9].
//Example 2:
//Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
//Output: 4
//Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
//Example 3:
//Input: matrix = [[1]]
//Output: 1
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 200
//	0 <= matrix[i][j] <= 231 - 1
int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int directions[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    int dfs(int i, int j) {
        if (dp[i][j] > 0) return dp[i][j];
        int ans = 1;
        for (int d = 0; d < 4; ++d) {
            int ni = i + directions[d][0];
            int nj = j + directions[d][1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]) {
                ans = max(ans, dfs(ni, nj) + 1);
            }
        }
        return dp[i][j] = ans;
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = max(ans, dfs(i, j));
        }
    }
    return ans;
}