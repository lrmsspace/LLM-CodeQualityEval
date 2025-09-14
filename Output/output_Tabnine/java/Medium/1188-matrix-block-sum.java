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
class Solution {
    public int[][] matrixBlockSum(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] dp = new int[m][n];
        int[][] answer = new int[m][n];
        
        // Initialize dp with the cumulative sum of the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) dp[i][j] = dp[i][j - 1] + mat[i][j];
                else dp[i][j] = mat[i][j];
                
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
            }
        }
        
        // Calculate the sum for each cell in the answer matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int topLeft = i - k >= 0 && j - k >= 0? dp[i - k][j - k] : 0;
                int topRight = j + k < n? dp[i - k][j + k] : 0;
                int bottomLeft = i + k < m && j - k >= 0? dp[i + k][j - k] : 0;
                int bottomRight = i + k < m && j + k < n? dp[i + k][j + k] : 0;
                
                answer[i][j] = dp[i][j] - topRight - bottomLeft + bottomRight;
            }
        }
        
        return answer;
        
    }
}