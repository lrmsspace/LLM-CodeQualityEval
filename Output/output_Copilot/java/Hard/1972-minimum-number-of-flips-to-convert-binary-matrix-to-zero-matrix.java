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
        int m = mat.length, n = mat[0].length;
        int target = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                target |= (mat[i][j] << (i * n + j));
            }
        }
        if (target == 0) return 0;
        
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < (1 << (m * n)); i++) {
            int flips = 0, curr = target;
            for (int j = 0; j < m * n; j++) {
                if ((i & (1 << j)) != 0) {
                    flips++;
                    curr ^= (1 << j);
                    if (j % n > 0) curr ^= (1 << (j - 1)); // left
                    if (j % n < n - 1) curr ^= (1 << (j + 1)); // right
                    if (j / n > 0) curr ^= (1 << (j - n)); // up
                    if (j / n < m - 1) curr ^= (1 << (j + n)); // down
                }
            }
            if (curr == 0) ans = Math.min(ans, flips);
        }
        
        return ans == Integer.MAX_VALUE ? -1 : ans;        
    }
}