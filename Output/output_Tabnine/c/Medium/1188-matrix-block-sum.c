/**https://leetcode.com/problems/matrix-block-sum/ */
//Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
//	i - k <= r <= i + k,
//	j - k <= c <= j + k, and
//	(r, c) is a valid position in the matrix.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
//Output: [[12,21,16],[27,45,33],[24,39,28]]
//Example 2:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
//Output: [[45,45,45],[45,45,45],[45,45,45]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n, k <= 100
//	1 <= mat[i][j] <= 100
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = matSize, n = *matColSize;
    int** dp = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            dp[i][j] = mat[i][j];
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
            if (i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
        }
    }
    
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) (*returnColumnSizes)[i] = n;
    
    int** result = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            int top = max(0, i - k), bottom = min(m - 1, i + k);
            int left = max(0, j - k), right = min(n - 1, j + k);
            result[i][j] = dp[bottom][right];
            if (top > 0) result[i][j] -= dp[top - 1][right];
            if (left > 0) result[i][j] -= dp[bottom][left - 1];
            if (top > 0 && left > 0) result[i][j] += dp[top - 1][left - 1];
        }
    }
    
    return result;
    
}