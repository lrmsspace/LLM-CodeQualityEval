/**https://leetcode.com/problems/rotting-oranges/ */
//You are given an m x n grid where each cell can have one of three values:
//	0 representing an empty cell,
//	1 representing a fresh orange, or
//	2 representing a rotten orange.
//Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
//Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
// 
//Example 1:
//Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
//Output: 4
//Example 2:
//Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
//Output: -1
//Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
//Example 3:
//Input: grid = [[0,2]]
//Output: 0
//Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 10
//	grid[i][j] is 0, 1, or 2.
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int i, j, k, m, n, cnt = 0, cnt2 = 0, cnt3 = 0;
    int *q = (int *)malloc(sizeof(int) * gridSize * gridColSize[0] * 4);
    int *q2 = (int *)malloc(sizeof(int) * gridSize * gridColSize[0] * 4);
    int q_head = 0, q_tail = 0;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 2) {
                q[q_tail++] = i;
                q[q_tail++] = j;
            }
            if (grid[i][j] == 1) cnt++;
        }
    }
    while (q_head < q_tail) {
        int x = q[q_head++];
        int y = q[q_head++];
        if (x > 0 && grid[x - 1][y] == 1) {
            grid[x - 1][y] = 2;
            q2[q_tail++] = x - 1;
            q2[q_tail++] = y;
            cnt--;
        }
    }
    while (q_head < q_tail) {
        int x = q[q_head++];
        int y = q[q_head++];
        if (x < m - 1 && grid[x + 1][y] == 1) {
            grid[x + 1][y] = 2;
            q2[q_tail++] = x + 1;
            q2[q_tail++] = y;
        }
    }
    while (q_head < q_tail) {
        int x = q[q_head++];
        int y = q[q_head++];
        if (y > 0 && grid[x][y - 1] == 1) {
            grid[x][y - 1] = 2;
            q2[q_tail++] = x;
            q2[q_tail++] = y - 1;
        }
    }
    while (q_head < q_tail) {
        int x = q[q_head++];
        int y = q[q_head++];
        if (x > 0 && grid[x - 1][y] == 1) {
            grid[x - 1][y] = 2;
            q2[q_tail++] = x - 1;
            q2[q_tail++] = y;
        }
    }
    while (q_head < q_tail) {
        int x = q[q_head++];
        int y = q[q_head++];
        if (y < n - 1 && grid[x][y + 1] == 1) {
            grid[x][y + 1] = 2;
            q2[q_tail++] = x;
            q2[q_tail++] = y + 1;
        }
    }
    while (q_head < q_tail) {
        int x = q[q_head++];
        int y = q[q_head++];
        if (x < m - 1 && grid[x + 1][y] == 1) {
            grid[x + 1][y] = 2;
            q2[q_tail++] = x + 1;
            q2[q_tail++] = y;
        }
    }
    while (q_head < q_tail) {
        int x = q[q_head++];
        int y = q[q_head++];
        if (y > 0 && grid[x][y - 1] == 1) {
            grid[x][y - 1] = 2;
            q2[q_tail++] = x;
            q2[q_tail++] = y - 1;
        }
    }
    while (q_head < q_tail) {
        int x = q[q_head++];
        int y = q[q_head++];
        if (x > 0 && grid[x - 1][y] == 1) {
            grid[x - 1][y] = 2;
            q2[q_tail++] = x - 1;
            q2[q_tail++] = y;
        }
    }
    while (q_head < q_tail) {
        int x = q[q_head++];
        int y = q[q_head++];
        if (y < m - 1 && grid[x][y + 1] == 1) {
            grid[x][y + 1] = 2;
            q2[q_tail++] = x;
            q2[q_tail++] = y + 1;
        }
    }
    while (q_head < q_tail) {
        int x = q[q_head++];
        int y = q[q_head++];
        if (x < n - 1 && grid[x + 1][y] == 1) {
            grid[x + 1][y] = 2;
            q2[q_tail++] = x + 1;
            q2[q_tail++] = y;
        }
    }
    while (q_head < q_tail) {
        int x = q2[q_head++];
        int y = q2[q_head++];
        if (y > 0 && grid[x][y - 1] == 1) {
            grid[x][y - 1] = 2;
            q[q_tail++] = x;
            q[q_tail++] = y - 1;
        }
    }
    return q_head;
}