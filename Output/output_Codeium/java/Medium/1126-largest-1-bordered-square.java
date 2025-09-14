/**https://leetcode.com/problems/largest-1-bordered-square/ */
//Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.
// 
//Example 1:
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
//Output: 9
//Example 2:
//Input: grid = [[1,1,0,0]]
//Output: 1
// 
//Constraints:
//	1 <= grid.length <= 100
//	1 <= grid[0].length <= 100
//	grid[i][j] is 0 or 1
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] left = new int[m][n], right = new int[m][n], up = new int[m][n], down = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    left[i][j] = j == 0 ? 1 : left[i][j - 1] + 1;
                    up[i][j] = i == 0 ? 1 : up[i - 1][j] + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    right[i][j] = j == n - 1 ? 1 : right[i][j + 1] + 1;
                    down[i][j] = i == m - 1 ? 1 : down[i + 1][j] + 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int side = Math.min(Math.min(left[i][j], right[i][j]), Math.min(up[i][j], down[i][j]));
                    res = Math.max(res, side * side);
                }
            }
        }
        return res;
    }
}