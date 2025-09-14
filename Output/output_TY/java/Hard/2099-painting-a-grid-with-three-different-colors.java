/**https://leetcode.com/problems/painting-a-grid-with-three-different-colors/ */
//You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
//Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: m = 1, n = 1
//Output: 3
//Explanation: The three possible colorings are shown in the image above.
//Example 2:
//Input: m = 1, n = 2
//Output: 6
//Explanation: The six possible colorings are shown in the image above.
//Example 3:
//Input: m = 5, n = 5
//Output: 580986
// 
//Constraints:
//	1 <= m <= 5
//	1 <= n <= 1000
class Solution {
    public int colorTheGrid(int m, int n) {
        int MOD = 1000_000_007;
        int[][] dp = new int[n][3 * m];
        int[][] color = new int[3 * m][3];
        for (int i = 0; i < 3 * m; i++) {
            for (int j = 0; j < 3; j++) {
                color[i][j] = -1;
            }
        }
        for (int i = 0; i < 3; i++) {
            color[0][i] = i;
        }
        for (int i = 1; i < 3 * m; i++) {
            for (int j = 0; j < 3; j++) {
                for (intk = 0; k < 3; k++) {
                    if (color[i - 1][k] != -1 && color[i - 1][k] != j) {
                        color[i][j] = color[i - 1][k];
                        break;
                    }
                }
            }
        } 
        for (int i = 0; i < m; i++) {
            int c1 = targetGrid[i][0];
            int c2 = targetGrid[i][1];
            int c3 = targetGrid[i][2];
            int ans = Integer.MAX_VALUE;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (color[j][c1] != -1 && color[k][c2] != -1 && color[l][c3] != -1) {
                            ans =Math.min(ans, color[j][c1] + color[k][c2] + color[l][c3]);
                        }
                    }
                }
            }
        } 
        return ans == Integer.MAX_VALUE ? -1 : ans; 
    }
}