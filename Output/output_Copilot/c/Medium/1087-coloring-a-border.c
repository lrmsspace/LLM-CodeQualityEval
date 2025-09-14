/**https://leetcode.com/problems/coloring-a-border/ */
//You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.
//Two squares are called adjacent if they are next to each other in any of the 4 directions.
//Two squares belong to the same connected component if they have the same color and they are adjacent.
//The border of a connected component is all the squares in the connected component that are either adjacent to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column).
//You should color the border of the connected component that contains the square grid[row][col] with color.
//Return the final grid.
// 
//Example 1:
//Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
//Output: [[3,3],[3,2]]
//Example 2:
//Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
//Output: [[1,3,3],[2,3,3]]
//Example 3:
//Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
//Output: [[2,2,2],[2,1,2],[2,2,2]]
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j], color <= 1000
//	0 <= row < m
//	0 <= col < n
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** colorBorder(int** grid, int gridSize, int* gridColSize, int row, int col, int color, int* returnSize, int** returnColumnSizes) {
    int m = gridSize, n = *gridColSize;
    int **ans = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        ans[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            ans[i][j] = grid[i][j];
        }
    }
    *returnSize = m;
    *returnColumnSizes = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    int vis[50][50] = {0};
    int color0 = grid[row][col];
    vis[row][col] = 1;
    int q[2500][2], l = 0, r = 0;
    q[r][0] = row, q[r][1] = col, r++;
    while (l < r) {
        int x = q[l][0], y = q[l][1];
        l++;
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty]) {
                continue;
            }
            if (grid[tx][ty] == color0) {
                vis[tx][ty] = 1;
                q[r][0] = tx, q[r][1] = ty, r++;
            } else {
                ans[x][y] = color;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] && (i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                ans[i][j] = color;
            }
        }
    }
    return ans;    
}