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
int regionsBySlashes(char ** grid, int gridSize){
    int n = gridSize;
    int m = n + 1;
    int *uf = malloc(sizeof(int) * m * m);
    for (int i = 0; i < m * m; i++) {
        uf[i] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int p = i * m + j;
            if (grid[i][j] == ' ') {
                union_set(uf, p, p + 1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int p = i * m + j;
            if (grid[i][j] == '/') {
                union_set(uf, p, p + m - 1);
            } else if (grid[i][j] == '\\') {
                union_set(uf, p, p+ 1);
        }
        }   
    }
    return find_set(uf, 0) == find_set(uf, n * m - 1);
}