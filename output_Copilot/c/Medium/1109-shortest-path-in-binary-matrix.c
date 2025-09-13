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
    if (grid[0][0] == 1) {
        return -1;
    }
    int n = gridSize;
    int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
    int queue[n * n][2];
    int front = 0, rear = 0;
    queue[rear][0] = 0;
    queue[rear][1] = 0;
    rear++;
    int step = 1;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;
            if (x == n - 1 && y == n - 1) {
                return step;
            }
            for (int j = 0; j < 8; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                }
            }
        }
        step++;
    }
    return -1;    
}