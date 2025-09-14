/**https://leetcode.com/problems/maximal-square/ */
//Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
// 
//Example 1:
//Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//Output: 4
//Example 2:
//Input: matrix = [["0","1"],["1","0"]]
//Output: 1
//Example 3:
//Input: matrix = [["0"]]
//Output: 0
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 300
//	matrix[i][j] is '0' or '1'.
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int** dp = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
    }
    int max = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + MIN(dp[i - 1][j - 1], MIN(dp[i - 1][j], dp[i][j - 1]));
                }
                max = MAX(max, dp[i][j]);
            }
        }
    }
    return max * max;
}