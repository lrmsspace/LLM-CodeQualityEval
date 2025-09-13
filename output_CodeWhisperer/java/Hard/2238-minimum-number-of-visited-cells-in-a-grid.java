/**https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/ */
//You are given a 0-indexed m x n integer matrix grid. Your initial position is at the top-left cell (0, 0).
//Starting from the cell (i, j), you can move to one of the following cells:
//	Cells (i, k) with j < k <= grid[i][j] + j (rightward movement), or
//	Cells (k, j) with i < k <= grid[i][j] + i (downward movement).
//Return the minimum number of cells you need to visit to reach the bottom-right cell (m - 1, n - 1). If there is no valid path, return -1.
// 
//Example 1:
//Input: grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
//Output: 4
//Explanation: The image above shows one of the paths that visits exactly 4 cells.
//Example 2:
//Input: grid = [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]
//Output: 3
//Explanation: The image above shows one of the paths that visits exactly 3 cells.
//Example 3:
//Input: grid = [[2,1,0],[1,0,0]]
//Output: -1
//Explanation: It can be proven that no path exists.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	0 <= grid[i][j] < m * n
//	grid[m - 1][n - 1] == 0
class Solution {
    public int minimumVisitedCells(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        // Priority queue to store {distance, row, col}
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{1, 0, 0}); // Start from (0,0) with distance 1
        
        // Keep track of minimum distance to each cell
        int[][] dist = new int[m][n];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        dist[0][0] = 1;
        
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int d = curr[0], r = curr[1], c = curr[2];
            
            // If we've found a better path already
            if (d > dist[r][c]) continue;
            
            // If we've reached the target
            if (r == m-1 && c == n-1) return d;
            
            // Try rightward movements
            int maxRight = Math.min(n-1, c + grid[r][c]);
            for (int nc = c + 1; nc <= maxRight; nc++) {
                if (d + 1 < dist[r][nc]) {
                    dist[r][nc] = d + 1;
                    pq.offer(new int[]{d + 1, r, nc});
                }
            }
            
            // Try downward movements
            int maxDown = Math.min(m-1, r + grid[r][c]);
            for (int nr = r + 1; nr <= maxDown; nr++) {
                if (d + 1 < dist[nr][c]) {
                    dist[nr][c] = d + 1;
                    pq.offer(new int[]{d + 1, nr, c});
                }
            }
        }
        
        return -1; // No path exists
    }
}
