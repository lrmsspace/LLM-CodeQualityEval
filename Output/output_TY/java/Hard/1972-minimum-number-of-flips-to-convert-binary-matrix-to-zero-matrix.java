/**https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/ */
//Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighbors if they share one edge.
//Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.
//A binary matrix is a matrix with all cells equal to 0 or 1 only.
//A zero matrix is a matrix with all cells equal to 0.
// 
//Example 1:
//Input: mat = [[0,0],[0,1]]
//Output: 3
//Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
//Example 2:
//Input: mat = [[0]]
//Output: 0
//Explanation: Given matrix is a zero matrix. We do not need to change it.
//Example 3:
//Input: mat = [[1,0,0],[1,0,0]]
//Output: -1
//Explanation: Given matrix cannot be a zero matrix.
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 3
//	mat[i][j] is either 0 or 1.
class Solution {
    public int minFlips(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int[][] dp = new int[n][m];
        int[][] dp2 = new int[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i][j] = Integer.MAX_VALUE;
                dp2[i][j] = Integer.MAX_VALUE;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    dp[i][j] = 0;
                    dp2[i][j] = 0;
                }
            }
        }  
        for(int i = 0; i < n; i++){ 
            for(int j = 0; j < m; j++){
                if(dp[i][j] == 0){
                    for(int k1 = i; k1 >= 0; k1--){
                        for(int k2 = j; k2 >= 0; k2--){
                            dp[i][j] = Math.min(dp[i][j], dp[k1 - 1][k2 - 1] + (i - k1 + 1) * (j - k2 + 1));
                        }
                    }
                }
        }
        } 
        return dp[n - 1][m - 1];
    }
}