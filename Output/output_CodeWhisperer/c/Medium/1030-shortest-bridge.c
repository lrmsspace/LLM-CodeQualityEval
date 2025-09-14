/**https://leetcode.com/problems/shortest-bridge/ */
//You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
//An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
//You may change 0's to 1's to connect the two islands to form one island.
//Return the smallest number of 0's you must flip to connect the two islands.
// 
//Example 1:
//Input: grid = [[0,1],[1,0]]
//Output: 1
//Example 2:
//Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
//Output: 2
//Example 3:
//Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
//Output: 1
// 
//Constraints:
//	n == grid.length == grid[i].length
//	2 <= n <= 100
//	grid[i][j] is either 0 or 1.
//	There are exactly two islands in grid.
int shortestBridge(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int* queue = (int*)malloc(sizeof(int) * n * n * 2);
    int head = 0, tail = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                queue[tail++] = i * n + j;
                queue[tail++] = 0;
                grid[i][j] = -1;
                while (head < tail) {
                    int x = queue[head++];
                    int y = queue[head++];
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            if (grid[nx][ny] == 1) {
                                grid[nx][ny] = -1;
                                queue[tail++] = nx * n + ny;
                                queue[tail++] = 0;
                            }
                        }
                    }
                }
                goto found;
            }
        }
    }
found:
    while (head < tail) {
        int x = queue[head++];
        int y = queue[head++];
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (grid[nx][ny] == 0) {
                    grid[nx][ny] = -2;
                    queue[tail++] = nx * n + ny;
                    queue[tail++] = y + 1;
                } else if (grid[nx][ny] == 1) {
                    return y;
                }
            }
        }
    }
    return -1;
}