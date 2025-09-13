/**https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/ */
//Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.
// 
//Example 1:
//Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
//Output: 2
//Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
//Example 2:
//Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
//Output: 0
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 300
//	0 <= mat[i][j] <= 104
//	0 <= threshold <= 105
int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int m = matSize, n = *matColSize;
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) dp[i][j] = mat[i][j];
            else dp[i][j] = mat[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    
    int ans = 0;
    for (int k = 1; k <= m && k <= n; k++) {
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                int sum = dp[i + k - 1][j + k - 1] - dp[i][j + k - 1] - dp[i + k - 1][j] + dp[i][j];
                if (sum <= threshold) ans = k;
            }
        }
    }
    return ans;
    
}