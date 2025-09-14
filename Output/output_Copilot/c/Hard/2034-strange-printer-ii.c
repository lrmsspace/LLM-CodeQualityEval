/**https://leetcode.com/problems/strange-printer-ii/ */
//There is a strange printer with the following two special requirements:
//	On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
//	Once the printer has used a color for the above operation, the same color cannot be used again.
//You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.
//Return true if it is possible to print the matrix targetGrid, otherwise, return false.
// 
//Example 1:
//Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
//Output: true
//Example 2:
//Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
//Output: true
//Example 3:
//Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
//Output: false
//Explanation: It is impossible to form targetGrid because it is not allowed to print the same color in different turns.
// 
//Constraints:
//	m == targetGrid.length
//	n == targetGrid[i].length
//	1 <= m, n <= 60
//	1 <= targetGrid[row][col] <= 60
bool isPrintable(int** targetGrid, int targetGridSize, int* targetGridColSize) {
    int m = targetGridSize, n = *targetGridColSize;
    int left[61], right[61], up[61], down[61];
    memset(left, 0x3f, sizeof(left));
    memset(right, -1, sizeof(right));
    memset(up, 0x3f, sizeof(up));
    memset(down, -1, sizeof(down));
    for (int color = 1; color <= 60; color++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (targetGrid[i][j] == color) {
                    left[color] = fmin(left[color], j);
                    right[color] = fmax(right[color], j);
                    up[color] = fmin(up[color], i);
                    down[color] = fmax(down[color], i);
                }
            }
        }
    }
    bool vis[61];
    memset(vis, 0, sizeof(vis));
    for (int color = 1; color <= 60; color++) {
        if (left[color] == 0x3f3f3f3f) {
            continue;
        }
        for (int i = up[color]; i <= down[color]; i++) {
            for (int j = left[color]; j <= right[color]; j++) {
                if (targetGrid[i][j] != color && !vis[targetGrid[i][j]]) {
                    return false;
                }
            }
        }
        for (int i = up[color]; i <= down[color]; i++) {
            for (int j = left[color]; j <= right[color]; j++) {
                vis[targetGrid[i][j]] = true;
            }
        }
    }
    return true;    
}