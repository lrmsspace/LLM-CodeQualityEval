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
int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = *gridColSize;
    int fresh = 0;
    int queue[m * n][2];
    int front = 0, rear = 0;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                fresh++;
            } else if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
        }
    }
    while (front < rear && fresh) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            int x = queue[front][0], y = queue[front][1];
            front++;
            for (int j = 0; j < 4; j++) {
                int newX = x + dir[j][0], newY = y + dir[j][1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    queue[rear][0] = newX;
                    queue[rear][1] = newY;
                    rear++;
                    fresh--;
                }
            }
        }
        res++;
    }
    return fresh ? -1 : res;    
}