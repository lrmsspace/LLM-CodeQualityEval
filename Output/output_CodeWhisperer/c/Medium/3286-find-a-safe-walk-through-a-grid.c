/*
 You are given an m x n binary matrix grid and an integer health.
 You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).
 You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.
 Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.
 Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.
 Example 1:
 Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1
 Output: true
 Explanation:
 The final cell can be reached safely by walking along the gray cells below.
 Example 2:
 Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3
 Output: false
 Explanation:
 A minimum of 4 health points is needed to reach the final cell safely.
 Example 3:
 Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5
 Output: true
 Explanation:
 The final cell can be reached safely by walking along the gray cells below.
 Any path that does not go through the cell (1, 1) is unsafe since your health will drop to 0 when reaching the final cell.
 Constraints:
 m == grid.length
 n == grid[i].length
 1 <= m, n <= 50
 2 <= m * n
 1 <= health <= m + n
 grid[i][j] is either 0 or 1.
*/

bool findSafeWalk(int** grid, int gridSize, int* gridColSize, int health) {
    int m = gridSize;
    int n = gridColSize[0];
    int i, j, k, l;
    int** dp = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = health;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (dp[i][j] > 0) {
                if (i == m - 1 && j == n - 1) {
                    return true;
                }
                for (k = i + 1; k < m; k++) {
                    if (grid[k][j] == 0) {
                        dp[k][j] = max(dp[k][j], dp[i][j] - 1);
                    }
                }
                for (l = j + 1; l < n; l++) {
                    if (grid[i][l] == 0) {
                        dp[i][l] = max(dp[i][l], dp[i][j] - 1);
                    }
                }
            }
        }
    }
    return false;    
}