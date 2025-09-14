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
    int cnt = 0;
    int graph[n * n * 4];
    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '/') {
                graph[(i * n + j) * 4 + 1] = graph[(i * n + j + 1) * 4] = 1;
            }
            if (grid[i][j] == '\\') {
                graph[(i * n + j) * 4 + 3] = graph[(i * n + j + 1) * 4 + 2] = 1;
            }
        }
    }
    int vis[n * n * 4];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n * n * 4; i++) {
        if (!vis[i]) {
            ++cnt;
            dfs(i, vis, graph, n);
        }
    }
    return cnt;
}