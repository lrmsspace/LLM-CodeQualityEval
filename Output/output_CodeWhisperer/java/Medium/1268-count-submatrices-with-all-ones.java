/**https://leetcode.com/problems/count-submatrices-with-all-ones/ */
//Given an m x n binary matrix mat, return the number of submatrices that have all ones.
// 
//Example 1:
//Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
//Output: 13
//Explanation: 
//There are 6 rectangles of side 1x1.
//There are 2 rectangles of side 1x2.
//There are 3 rectangles of side 2x1.
//There is 1 rectangle of side 2x2. 
//There is 1 rectangle of side 3x1.
//Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
//Example 2:
//Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
//Output: 24
//Explanation: 
//There are 8 rectangles of side 1x1.
//There are 5 rectangles of side 1x2.
//There are 2 rectangles of side 1x3. 
//There are 4 rectangles of side 2x1.
//There are 2 rectangles of side 2x2. 
//There are 2 rectangles of side 3x1. 
//There is 1 rectangle of side 3x2. 
//Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
// 
//Constraints:
//	1 <= m, n <= 150
//	mat[i][j] is either 0 or 1.
class Solution {
    public int numSubmat(int[][] mat) {
        int[][] dp = new int[mat.length + 1][mat[0].length + 1];
        int sum = 0;
        for (int i = 1; i <= mat.length; i++) {
            for (int j = 1; j <= mat[0].length; j++) {
                if (mat[i - 1][j - 1] == 1) {
                    dp[i][j] = dp[i][j - 1] + 1;
                    int min = Integer.MAX_VALUE;
                    for (int k = i; k > 0; k--) {
                        min = Math.min(min, dp[k][j]);
                        sum += min;
                    }
                }
            }
        }
        return sum;     
    }
}