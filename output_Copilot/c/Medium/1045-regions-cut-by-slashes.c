/**https://leetcode.com/problems/regions-cut-by-slashes/ */
//An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
//Given the grid grid represented as a string array, return the number of regions.
//Note that backslash characters are escaped, so a '\' is represented as '\\'.
// 
//Example 1:
//Input: grid = [" /","/ "]
//Output: 2
//Example 2:
//Input: grid = [" /","  "]
//Output: 1
//Example 3:
//Input: grid = ["/\\","\\/"]
//Output: 5
//Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
// 
//Constraints:
//	n == grid.length == grid[i].length
//	1 <= n <= 30
//	grid[i][j] is either '/', '\', or ' '.
int regionsBySlashes(char** grid, int gridSize) {
    int n = gridSize;
    int m = 3 * n;
    int *fa = (int *)malloc(sizeof(int) * m * m);
    for (int i = 0; i < m * m; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int idx = 3 * (i * n + j);
            if (grid[i][j] == '/') {
                fa[idx + 1] = fa[idx];
                fa[idx + 2] = fa[idx];
            } else if (grid[i][j] == '\\') {
                fa[idx + 1] = fa[idx + 2];
            } else {
                fa[idx + 1] = fa[idx];
                fa[idx + 2] = fa[idx];
            }
            if (i > 0) {
                int up = 3 * ((i - 1) * n + j) + 2;
                int down = 3 * (i * n + j);
                if (find(fa, up) != find(fa, down)) {
                    fa[find(fa, up)] = find(fa, down);
                }
            }
            if (j > 0) {
                int left = 3 * (i * n + j - 1) + 1;
                int right = 3 * (i * n + j) + 1;
                if (find(fa, left) != find(fa, right)) {
                    fa[find(fa, left)] = find(fa, right);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m * m; i++) {
        if (find(fa, i) == i) {
            ans++;
        }
    }
    free(fa);
    return ans;    
}