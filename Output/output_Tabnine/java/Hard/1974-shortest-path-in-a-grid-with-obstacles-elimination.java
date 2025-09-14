/**https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/ */
//You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
//Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.
// 
//Example 1:
//Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
//Output: 6
//Explanation: 
//The shortest path without eliminating any obstacle is 10.
//The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
//Example 2:
//Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
//Output: -1
//Explanation: We need to eliminate at least two obstacles to find such a walk.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 40
//	1 <= k <= m * n
//	grid[i][j] is either 0 or 1.
//	grid[0][0] == grid[m - 1][n - 1] == 0
class Solution {
    public int shortestPath(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        int[][] dp = new int[m][n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0][0] = 0;
        
        Queue<int[]> queue = new PriorityQueue<>((a, b) -> dp[a[0]][a[1]] - dp[b[0]][b[1]]);
        queue.offer(new int[]{0, 0});
        
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0], y = cur[1];
            if (x == m - 1 && y == n - 1) return dp[x][y];
            
            for (int[] dir : new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 1 || dp[nx][ny] <= dp[x][y] + 1) continue;
                
                dp[nx][ny] = dp[x][y] + 1;
                queue.offer(new int[]{nx, ny});
            }
            
            if (k > 0 && (x == 0 || y == 0 || x == m - 1 || y == n - 1)) {
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        if (grid[i][j] == 1 && dp[i][j] <= dp[x][y] + 1) {
                            dp[i][j] = Integer.MAX_VALUE;
                            queue.remove(new int[]{i, j});
                        }
                    }
                }
                k--;
            }
        }
        
        return -1;
    }
}