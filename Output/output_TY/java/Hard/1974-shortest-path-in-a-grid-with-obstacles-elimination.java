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
        int n = grid.length;
        int m = grid[0].length;
        int[][] dp = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        dp[0][0] = 0;
        int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0, 0});
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int i = cur[0], j = cur[1], k = cur[2];
            for (int[] d : dir) {
                int x = i + d[0], y = j + d[1];
                if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 1) continue;
                if (k == 0 && dp[x][y] > dp[i][j] + 1) {
                    dp[x][y] = dp[i][j] + 1;
                    q.add(new int[]{x, y, 1});
                }
            }
        } 
        return dp;
    }
}