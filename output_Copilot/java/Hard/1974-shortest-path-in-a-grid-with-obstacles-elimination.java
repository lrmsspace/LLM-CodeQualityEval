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
        int[][][] dist = new int[m][n][k + 1];
        for (int[][] d : dist) {
            for (int[] dd : d) {
                Arrays.fill(dd, Integer.MAX_VALUE);
            }
        }
        dist[0][0][0] = 0;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0, 0});
        
        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int x = curr[0], y = curr[1], obstacles = curr[2];
            
            for (int[] dir : directions) {
                int newX = x + dir[0], newY = y + dir[1];
                
                if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                    int newObstacles = obstacles + grid[newX][newY];
                    if (newObstacles <= k && dist[newX][newY][newObstacles] > dist[x][y][obstacles] + 1) {
                        dist[newX][newY][newObstacles] = dist[x][y][obstacles] + 1;
                        queue.offer(new int[]{newX, newY, newObstacles});
                    }
                }
            }
        }
        
        int minSteps = Integer.MAX_VALUE;
        for (int i = 0; i <= k; i++) {
            minSteps = Math.min(minSteps, dist[m - 1][n - 1][i]);
        }
        
        return minSteps == Integer.MAX_VALUE ? -1 : minSteps;        
    }
}