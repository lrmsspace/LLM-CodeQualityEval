/**https://leetcode.com/problems/escape-the-spreading-fire/ */
//You are given a 0-indexed 2D integer array grid of size m x n which represents a field. Each cell has one of three values:
//	0 represents grass,
//	1 represents fire,
//	2 represents a wall that you and fire cannot pass through.
//You are situated in the top-left cell, (0, 0), and you want to travel to the safehouse at the bottom-right cell, (m - 1, n - 1). Every minute, you may move to an adjacent grass cell. After your move, every fire cell will spread to all adjacent cells that are not walls.
//Return the maximum number of minutes that you can stay in your initial position before moving while still safely reaching the safehouse. If this is impossible, return -1. If you can always reach the safehouse regardless of the minutes stayed, return 109.
//Note that even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as safely reaching the safehouse.
//A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
// 
//Example 1:
//Input: grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
//Output: 3
//Explanation: The figure above shows the scenario where you stay in the initial position for 3 minutes.
//You will still be able to safely reach the safehouse.
//Staying for more than 3 minutes will not allow you to safely reach the safehouse.
//Example 2:
//Input: grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
//Output: -1
//Explanation: The figure above shows the scenario where you immediately move towards the safehouse.
//Fire will spread to any cell you move towards and it is impossible to safely reach the safehouse.
//Thus, -1 is returned.
//Example 3:
//Input: grid = [[0,0,0],[2,2,0],[1,2,0]]
//Output: 1000000000
//Explanation: The figure above shows the initial grid.
//Notice that the fire is contained by walls and you will always be able to safely reach the safehouse.
//Thus, 109 is returned.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	2 <= m, n <= 300
//	4 <= m * n <= 2 * 104
//	grid[i][j] is either 0, 1, or 2.
//	grid[0][0] == grid[m - 1][n - 1] == 0
class Solution {
    private static final int[] DR = {-1, 1, 0, 0};
    private static final int[] DC = {0, 0, -1, 1};
    private static final int MAX_ANSWER = 1_000_000_000;
    
    public int maximumMinutes(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        // Binary search on the waiting time
        int left = 0;
        int right = MAX_ANSWER;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canReachSafehouse(grid, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
    private boolean canReachSafehouse(int[][] grid, int waitTime) {
        int m = grid.length;
        int n = grid[0].length;
        
        // Track fire spread
        Queue<int[]> fireQueue = new LinkedList<>();
        boolean[][] fireCells = new boolean[m][n];
        
        // Initialize fire positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fireQueue.offer(new int[]{i, j});
                    fireCells[i][j] = true;
                } else if (grid[i][j] == 2) {
                    fireCells[i][j] = true;
                }
            }
        }
        
        // Spread fire for waitTime minutes
        for (int t = 0; t < waitTime; t++) {
            if (!spreadFire(fireQueue, fireCells, grid)) {
                // Fire reached safehouse
                if (fireCells[m-1][n-1]) return false;
            }
        }
        
        // Check if we can reach safehouse from initial position
        boolean[][] visited = new boolean[m][n];
        Queue<int[]> personQueue = new LinkedList<>();
        personQueue.offer(new int[]{0, 0});
        visited[0][0] = true;
        
        // Copy fire state for person's movement
        boolean[][] currentFire = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            currentFire[i] = fireCells[i].clone();
        }
        Queue<int[]> currentFireQueue = new LinkedList<>(fireQueue);
        
        while (!personQueue.isEmpty()) {
            // Spread fire after person's move
            spreadFire(currentFireQueue, currentFire, grid);
            
            int size = personQueue.size();
            for (int i = 0; i < size; i++) {
                int[] curr = personQueue.poll();
                int r = curr[0], c = curr[1];
                
                // Reached safehouse
                if (r == m-1 && c == n-1) return true;
                
                // If current position is on fire, person dies
                if (currentFire[r][c]) continue;
                
                // Try all four directions
                for (int d = 0; d < 4; d++) {
                    int nr = r + DR[d];
                    int nc = c + DC[d];
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                        !visited[nr][nc] && grid[nr][nc] != 2 && !currentFire[nr][nc]) {
                        visited[nr][nc] = true;
                        personQueue.offer(new int[]{nr, nc});
                    }
                }
            }
        }
        
        return false;
    }
    
    private boolean spreadFire(Queue<int[]> fireQueue, boolean[][] fireCells, int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        boolean spread = false;
        
        int size = fireQueue.size();
        for (int i = 0; i < size; i++) {
            int[] curr = fireQueue.poll();
            
            for (int d = 0; d < 4; d++) {
                int nr = curr[0] + DR[d];
                int nc = curr[1] + DC[d];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                    !fireCells[nr][nc] && grid[nr][nc] != 2) {
                    fireCells[nr][nc] = true;
                    fireQueue.offer(new int[]{nr, nc});
                    spread = true;
                }
            }
        }
        
        return spread;
    }
}
