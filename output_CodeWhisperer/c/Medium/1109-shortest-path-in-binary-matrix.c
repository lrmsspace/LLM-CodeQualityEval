/**https://leetcode.com/problems/shortest-path-in-binary-matrix/ */
//Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
//A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
//	All the visited cells of the path are 0.
//	All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
//The length of a clear path is the number of visited cells of this path.
// 
//Example 1:
//Input: grid = [[0,1],[1,0]]
//Output: 2
//Example 2:
//Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
//Output: 4
//Example 3:
//Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
//Output: -1
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 100
//	grid[i][j] is 0 or 1
int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
        return -1;
    }
    int** visited = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        visited[i] = (int*)malloc(sizeof(int) * n);
        memset(visited[i], 0, sizeof(int) * n);
    }
    int** distance = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        distance[i] = (int*)malloc(sizeof(int) * n);
        memset(distance[i], 0, sizeof(int) * n);
    }
    int** queue = (int**)malloc(sizeof(int*) * n * n);
    for (int i = 0; i < n * n; i++) {
        queue[i] = (int*)malloc(sizeof(int) * 2);
        memset(queue[i], 0, sizeof(int) * 2);
    }
    int head = 0, tail = 0;
    queue[tail][0] = 0;
    queue[tail][1] = 0;
    tail++;
    visited[0][0] = 1;
    distance[0][0] = 1;
    while (head < tail) {
        int x = queue[head][0];
        int y = queue[head][1];
        head++;
        if (x == n - 1 && y == n - 1) {
            return distance[x][y];
        }
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && visited[nx][ny] == 0) {
                    queue[tail][0] = nx;
                    queue[tail][1] = ny;
                    tail++;
                    visited[nx][ny] = 1;
                    distance[nx][ny] = distance[x][y] + 1;
                }
            }
        }
    }
    return -1;
}