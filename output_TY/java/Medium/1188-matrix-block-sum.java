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
        int[][] sum = new int[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                sum[i][j] = mat[i][j];
                if(i > 0){
                    sum[i][j] += sum[i-1][j];
                }
                if(j > 0){
                    sum[i][j] += sum[i][j-1];
                }
                if(i > 0 && j > 0){
                    sum[i][j] -= sum[i-1][j-1];
                }
            }
        }
        int[][] ans = new int[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int x1 = Math.max(0, i - k);
                int y1 = Math.max(0, j - k);
                int x2 = Math.min(m-1, i + k);
                int y2 = Math.min(n-1, j + k);
                ans[i][j] = sum[x2][y2];
                if(x1 > 0){
                    ans[i][j] -= sum[x1-1][y2];
                }
            }
        }
        return ans;
    }
}