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
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int firstIsland[n][n];
    int queue[n * n][2];
    int front = 0, rear = 0;
    int found = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !found) {
                found = 1;
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
                firstIsland[i][j] = 1;
            }
        }
    }
    int level = 0;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;
            for (int j = 0; j < 4; j++) {
                int nx = x + directions[j][0];
                int ny = y + directions[j][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !firstIsland[nx][ny]) {
                    if (grid[nx][ny] == 1) {
                        return level;
                    }
                    firstIsland[nx][ny] = 1;
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                }
            }
        }
        level++;
    }
    return level;
}