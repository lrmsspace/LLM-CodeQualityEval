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
    int* parent = (int*)malloc(sizeof(int) * n * n);
    for (int i = 0; i < n * n; i++) {
        parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[x] = y;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) {
                unionSet((i - 1) * n + j, i * n + j);
            }
            if (j > 0) {
                unionSet(i * n + j - 1, i * n + j);
            }
            if (grid[i][j] != '/') {
                unionSet(i * n + j, (i + 1) * n + j);
                unionSet(i * n + j + 1, i * n + j);
            }
            if (grid[i][j] != '\\') {
                unionSet(i * n + j, i * n + j + 1);
                unionSet((i + 1) * n + j, i * n + j);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n * n; i++) {
        if (parent[i] == i) {
            count++;
        }
    }
    return count;
}