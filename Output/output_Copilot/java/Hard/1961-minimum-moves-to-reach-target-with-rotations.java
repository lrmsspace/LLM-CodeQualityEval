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
class Solution {
    public int minimumMoves(int[][] grid) {
        int n = grid.length;
        int[][][] dp = new int[n][n][2];
        for (int[][] d : dp) {
            for (int[] dd : d) {
                Arrays.fill(dd, Integer.MAX_VALUE);
            }
        }
        dp[0][1][0] = 0; // snake is horizontal at (0, 0) and (0, 1)
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 1, 0}); // x, y, orientation
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0], y = cur[1], o = cur[2];
            if (x == n - 1 && y == n - 2 && o == 0) return dp[x][y][o]; // reached target
            // move right
            if (y + 1 < n && grid[x][y + 1] == 0 && dp[x][y + 1][o] > dp[x][y][o] + 1) {
                dp[x][y + 1][o] = dp[x][y][o] + 1;
                queue.offer(new int[]{x, y + 1, o});
            }
            // move down
            if (x + 1 < n && grid[x + 1][y] == 0 && dp[x + 1][y][o] > dp[x][y][o] + 1) {
                dp[x + 1][y][o] = dp[x][y][o] + 1;
                queue.offer(new int[]{x + 1, y, o});
            }
            // rotate clockwise
            if (o == 0 && x + 1 < n && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0 && dp[x + 1][y][1] > dp[x][y][o]) {
                dp[x + 1][y][1] = dp[x][y][o];
                queue.offer(new int[]{x + 1, y, 1});
            }
            // rotate counterclockwise
            if (o == 1 && y + 1 < n && grid[x][y + 1] ==  0 && grid[x + 1][y + 1] == 0 && dp[x][y + 1][0] > dp[x][y][o]) {
                dp[x][y + 1][0] = dp[x][y][o];
                queue.offer(new int[]{x, y + 1, 0});
            }      
    }
        return -1; // no path found
    }
}