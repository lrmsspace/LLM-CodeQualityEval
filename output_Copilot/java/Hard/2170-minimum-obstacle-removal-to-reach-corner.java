/**https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/ */
//You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:
//	0 represents an empty cell,
//	1 represents an obstacle that may be removed.
//You can move up, down, left, or right from and to an empty cell.
//Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).
// 
//Example 1:
//Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
//Output: 2
//Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
//It can be shown that we need to remove at least 2 obstacles, so we return 2.
//Note that there may be other ways to remove 2 obstacles to create a path.
//Example 2:
//Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
//Output: 0
//Explanation: We can move from (0, 0) to (2, 4) without removing any obstacles, so we return 0.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	2 <= m * n <= 105
//	grid[i][j] is either 0 or 1.
//	grid[0][0] == grid[m - 1][n - 1] == 0
class Solution {
    public int minimumObstacles(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] dist = new int[m][n];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        dist[0][0] = 0;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[2]));
        pq.offer(new int[]{0, 0, 0}); // {x, y, obstacles removed}
        
        while (!pq.isEmpty()) {
            int[] cell = pq.poll();
            int x = cell[0], y = cell[1], obstacles = cell[2];
            
            if (x == m - 1 && y == n - 1) {
                return obstacles;
            }
            
            for (int[] dir : new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newObstacles = obstacles + grid[nx][ny];
                    if (newObstacles < dist[nx][ny]) {
                        dist[nx][ny] = newObstacles;
                        pq.offer(new int[]{nx, ny, newObstacles});
                    }
                }
            }
        }
        
        return -1; // If no path found    
    }
}