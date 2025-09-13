/**https://leetcode.com/problems/sort-the-matrix-diagonally/ */
//A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
//Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.
// 
//Example 1:
//Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
//Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
//Example 2:
//Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
//Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 100
//	1 <= mat[i][j] <= 100
class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int[][] dp = new int[mat.length + 1][mat[0].length + 1];
        for (int i = 1; i <= mat.length; i++) {
            for (int j = 1; j <= mat[0].length; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int[][] res = new int[mat.length][mat[0].length];
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                int r1 = Math.max(0, i - k), c1 = Math.max(0, j - k), r2 = Math.min(mat.length - 1, i + k), c2 = Math.min(mat[0].length - 1, j + k);
                r1++; c1++; r2++; c2++;
                res[i][j] = dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
            }
        }
        return res;      
    }
}