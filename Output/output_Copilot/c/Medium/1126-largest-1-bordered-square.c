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


int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[100][100] = {0};
    int b[100][100] = {0};
    int c[100][100] = {0};
    int d[100][100] = {0};
    int e[100][100] = {0};
    int f[100][100] = {0};
    int g[100][100] = {0};
    int h[100][100] = {0};
    int ans = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < gridColSize[i]; j++) {
            if(grid[i][j] == 1) {
                a[i][j] = 1;
                b[i][j] = 1;
                c[i][j] = 1;
                d[i][j] = 1;
            }
        }
    }
    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < gridColSize[i]; j++) {
            if(i > 0 && a[i][j] > 0) {
                a[i][j] += a[i - 1][j];
            }
            if(j > 0 && b[i][j] > 0) {
                b[i][j] += b[i][j - 1];
            }
        }
    }
    for(i = gridSize - 1; i >= 0; i--) {
        for(j = gridColSize[i] - 1; j >= 0; j--) {
            if(i < gridSize - 1 && c[i][j] > 0) {
                c[i][j] += c[i + 1][j];
            }
            if(j < gridColSize[i] - 1 && d[i][j] > 0) {
                d[i][j] += d[i][j + 1];
            }
        }
    }
    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < gridColSize[i]; j++) {
            if(a[i][j] > 1 && b[i][j] > 1) {
                for(k = 1; k < a[i][j]; k++) {
                    if(i + k < gridSize && j + k < gridColSize[i + k] && c[i + k][j] > k && d[i][j + k] > k) {
                        ans = max(ans, (k + 1) * (k + 1));
                    }
                }
            }
        }
    }
    return ans;
}