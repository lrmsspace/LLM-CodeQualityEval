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
    int head = 0;
    int tail = 0;
    int queue[10000][2];
    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < gridColSize[i]; j++) {
            if(grid[i][j] == 1) {
                queue[tail][0] = i;
                queue[tail][1] = j;
                tail++;
                a[i][j] = 1;
            }
        }
    }
    while(head < tail) {
        i = queue[head][0];
        j = queue[head][1];
        head++;
        for(k = 0; k < 4; k++) {
            l = i + dx[k];
            m = j + dy[k];
            if(l >= 0 && l < gridSize && m >= 0 && m < gridColSize[l] && a[l][m] == 0) {
                a[l][m] = 1;
                queue[tail][0] = l;
                queue[tail][1] = m;
                tail++;
            }
        }
    }
    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < gridColSize[i]; j++) {
            if(grid[i][j] == 1) {
                b[i][j] = 1;
            }
        }
    }
    head = 0;
    tail = 0;
    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < gridColSize[i]; j++) {
            if(b[i][j] == 1) {
                queue[tail][0] = i;
                queue[tail][1] = j;
                tail++;
                b[i][j] = 2;
            }
        }
    }
        
}