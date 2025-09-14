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
    int fresh = 0, rotten = 0;
    int queueSize = 0, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) ++fresh;
            else if (grid[i][j] == 2) {
                queue[queueSize++] = i * n + j;
                ++rotten;
            }
        }
    }
    
    if (fresh == 0) return 0;
    
    int ans = 0;
    while (queueSize > 0) {
        int size = queueSize;
        queueSize = 0;
        ++ans;
        for (int k = 0; k < size; ++k) {
            int x = queue[k] / n, y = queue[k] % n;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    queue[queueSize++] = nx * n + ny;
                    --fresh;
                    ++rotten;
                }
            }
        }
    }
    
    return fresh == 0? ans : -1;
    
}