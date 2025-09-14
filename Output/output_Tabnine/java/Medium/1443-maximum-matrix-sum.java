/**https://leetcode.com/problems/maximum-matrix-sum/ */
//You are given an n x n integer matrix. You can do the following operation any number of times:
//	Choose any two adjacent elements of matrix and multiply each of them by -1.
//Two elements are considered adjacent if and only if they share a border.
//Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
// 
//Example 1:
//Input: matrix = [[1,-1],[-1,1]]
//Output: 4
//Explanation: We can follow the following steps to reach sum equals 4:
//- Multiply the 2 elements in the first row by -1.
//- Multiply the 2 elements in the first column by -1.
//Example 2:
//Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
//Output: 16
//Explanation: We can follow the following step to reach sum equals 16:
//- Multiply the 2 last elements in the second row by -1.
// 
//Constraints:
//	n == matrix.length == matrix[i].length
//	2 <= n <= 250
//	-105 <= matrix[i][j] <= 105
class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int n = matrix.length;
        int[][] dp = new int[n][n];
        int[] rowSum = new int[n];
        int[] colSum = new int[n];
        
        for (int i = 0; i < n; i++) {
            rowSum[i] = matrix[i][0];
            colSum[i] = matrix[0][i];
            for (int j = 1; j < n; j++) {
                rowSum[i] += matrix[i][j];
                colSum[i] += matrix[j][i];
            }
        }
        
        dp[0][0] = matrix[0][0];
        
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i-1] + matrix[0][i];
            dp[i][0] = dp[i-1][0] + matrix[i][0];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]) + matrix[i][j];
            }
        }
        
        int maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            maxSum = Math.max(maxSum, Math.max(rowSum[i], colSum[i]));
        }
        
        return maxSum - dp[n-1][n-1];
        
    }
}