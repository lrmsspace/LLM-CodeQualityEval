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
        int m = grid.length, n = grid[0].length;
        int[][] dp = new int[m][n];
        Arrays.fill(dp[0], Integer.MAX_VALUE);
        dp[0][0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        pq.offer(new int[]{0, 0, 0});
        
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int i = cur[0], j = cur[1];
            int steps = cur[2];
            
            if (i == m - 1 && j == n - 1) {
                return steps;
            }
            
            for (int k = j + 1; k <= grid[i][j] + j; k++) {
                int ni = Math.min(m - 1, i + k - grid[i][j] - 1);
                int nj = Math.min(n - 1, j + k - grid[i][j] - 1);
                if (dp[ni][nj] > steps + 1) {
                    dp[ni][nj] = steps + 1;
                    pq.offer(new int[]{ni, nj, dp[ni][nj]});
                }
            }
            
            for (int k = i + 1; k <= grid[i][j] + i; k++) {
                int ni = Math.min(m - 1, i + k - grid[i][j] - 1);
                int nj = Math.min(n - 1, j + k - grid[i][j] - 1);
                if (dp[ni][nj] > steps + 1) {
                    dp[ni][nj] = steps + 1;
                    pq.offer(new int[]{ni, nj, dp[ni][nj]});
                }
            }
    
        }
        
        return -1;
    }
}