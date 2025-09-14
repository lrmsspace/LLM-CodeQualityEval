/**https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/ */
//In an n*n grid, there is a snake that spans 2 cells and starts moving from the top left corner at (0, 0) and (0, 1). The grid has empty cells represented by zeros and blocked cells represented by ones. The snake wants to reach the lower right corner at (n-1, n-2) and (n-1, n-1).
//In one move the snake can:
//	Move one cell to the right if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
//	Move down one cell if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
//	Rotate clockwise if it's in a horizontal position and the two cells under it are both empty. In that case the snake moves from (r, c) and (r, c+1) to (r, c) and (r+1, c).
//	
//	Rotate counterclockwise if it's in a vertical position and the two cells to its right are both empty. In that case the snake moves from (r, c) and (r+1, c) to (r, c) and (r, c+1).
//	
//Return the minimum number of moves to reach the target.
//If there is no way to reach the target, return -1.
// 
//Example 1:
//Input: grid = [[0,0,0,0,0,1],
//               [1,1,0,0,1,0],
//               [0,0,0,0,1,1],
//               [0,0,1,0,1,0],
//               [0,1,1,0,0,0],
//               [0,1,1,0,0,0]]
//Output: 11
//Explanation:
//One possible solution is [right, right, rotate clockwise, right, down, down, down, down, rotate counterclockwise, right, down].
//Example 2:
//Input: grid = [[0,0,1,1,1,1],
//               [0,0,0,0,1,1],
//               [1,1,0,0,0,1],
//               [1,1,1,0,0,1],
//               [1,1,1,0,0,1],
//               [1,1,1,0,0,0]]
//Output: 9
// 
//Constraints:
//	2 <= n <= 100
//	0 <= grid[i][j] <= 1
//	It is guaranteed that the snake starts at empty cells.


int minimumMoves(int** grid, int gridSize, int* gridColSize){
    int n = gridSize;
    int m = gridColSize[0];
    int dp[n][m][4] = {0};
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int dir[4] = {0, 1, 2, 3};
    int i, j, k, x, y, d, t, ans = -1;
    int q[n*m*4][3];
    memset(q, 0, sizeof(q));
    int h = 0, t = 0;
    q[t][0] = 0; q[t][1] = 0; q[t][2] = 0;
    t++;
    while (h < t) {
        i = q[h][0]; j = q[h][1]; d = q[h][2];
        h++;
        if (i == n-1 && j == m-2) {
            ans = dp[i][j][d];
            break;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (d = 0; d < 4; d++) {
                if (dp[i][j][d] == -1) continue;
                for (k = 0; k < 4; k++) {
                    x = i + dx[k]; y = j + dy[k];
                   if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y]) continue;
                }
            }
        }
    }
    return ans;
}