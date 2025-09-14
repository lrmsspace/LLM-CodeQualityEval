/**https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/ */
//You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.
//The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).
//Find the kth largest value (1-indexed) of all the coordinates of matrix.
// 
//Example 1:
//Input: matrix = [[5,2],[1,6]], k = 1
//Output: 7
//Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.
//Example 2:
//Input: matrix = [[5,2],[1,6]], k = 2
//Output: 5
//Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.
//Example 3:
//Input: matrix = [[5,2],[1,6]], k = 3
//Output: 4
//Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 1000
//	0 <= matrix[i][j] <= 106
//	1 <= k <= m * n
int kthLargestValue(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int m = matrixSize, n = matrixColSize[0];
    int **dp = (int **)malloc(sizeof(int *) * (m + 1));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)malloc(sizeof(int) * (n + 1));
        memset(dp[i], 0, sizeof(int) * (n + 1));
    }
    int *res = (int *)malloc(sizeof(int) * (m * n));
    int resSize = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i - 1][j - 1];
            res[resSize++] = dp[i][j];
        }
    }
    qsort(res, resSize, sizeof(int), cmp);
    return res[resSize - k];    
}