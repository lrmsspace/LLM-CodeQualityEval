/**https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/ */
//You are given a 2D integer array grid of size m x n, where each cell contains a positive integer.
//A cornered path is defined as a set of adjacent cells with at most one turn. More specifically, the path should exclusively move either horizontally or vertically up to the turn (if there is one), without returning to a previously visited cell. After the turn, the path will then move exclusively in the alternate direction: move vertically if it moved horizontally, and vice versa, also without returning to a previously visited cell.
//The product of a path is defined as the product of all the values in the path.
//Return the maximum number of trailing zeros in the product of a cornered path found in grid.
//Note:
//	Horizontal movement means moving in either the left or right direction.
//	Vertical movement means moving in either the up or down direction.
// 
//Example 1:
//Input: grid = [[23,17,15,3,20],[8,1,20,27,11],[9,4,6,2,21],[40,9,1,10,6],[22,7,4,5,3]]
//Output: 3
//Explanation: The grid on the left shows a valid cornered path.
//It has a product of 15 * 20 * 6 * 1 * 10 = 18000 which has 3 trailing zeros.
//It can be shown that this is the maximum trailing zeros in the product of a cornered path.
//The grid in the middle is not a cornered path as it has more than one turn.
//The grid on the right is not a cornered path as it requires a return to a previously visited cell.
//Example 2:
//Input: grid = [[4,3,2],[7,6,1],[8,8,8]]
//Output: 0
//Explanation: The grid is shown in the figure above.
//There are no cornered paths in the grid that result in a product with a trailing zero.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	1 <= grid[i][j] <= 1000
int maxTrailingZeros(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = *gridColSize;
    int i, j, k, l, x, y, z, t, p, q, r, s, u, v, w, a, b, c, d, e, f, g, h, j1, j2, j3, j4, j5, j6, j7, j8, j9, j10, j11, j12, j13, j14, j15, j16, j17, j18, j19,j20, j21, j22, j23, j24, j         = 0;
    int row[m][26], col[n][26], row_max[m], col_max[n], row_min[m], col_min[n];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(row_max, 0, sizeof(row_max));
    memset(col_max, 0, sizeof(col_max));
    memset(row_min, 0, sizeof(row_min));
    memset(col_min, 0, sizeof(col_min));
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            row[i][s[i][j] - 'A']++;
            col[j][s[i][j] - 'A']++;
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < 26; j++) {
            row_max[i] = max(row_max[i], row[i][j]);
            row_min[i] = min(row_min[i], row[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            col_max[i] = max(col_max[i], col[i][j]);
            col_min[i] = min(col_min[i], col[i][j]);
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            int row_val = row_max[i] - row_min[i];
            int col_val = col_max[j] - col_min[j];
            int val = min(row_val, col_val);
            if (val > 0) {
                ans = max(ans,val * grid[i][j]);
            }
        }
    }
    return ans;
}