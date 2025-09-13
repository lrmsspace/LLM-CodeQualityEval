/**https://leetcode.com/problems/number-of-enclaves/ */
//You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
//A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
//Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
// 
//Example 1:
//Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
//Output: 3
//Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
//Example 2:
//Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
//Output: 0
//Explanation: All 1s are either on the boundary or can reach the boundary.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 500
//	grid[i][j] is either 0 or 1.
class Solution {
    public int numEnclaves(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int count = 0;
        
        // Initialize a queue to store the coordinates of land cells that need to be checked
        Queue<int[]> queue = new LinkedList<>();
        
        // Add the coordinates of the land cells on the boundary to the queue
        for (int i = 0; i < m; i++) {
            queue.offer(new int[]{i, 0});
            queue.offer(new int[]{i, n - 1});
        }
        for (int j = 1; j < n - 1; j++) {
            queue.offer(new int[]{0, j});
            queue.offer(new int[]{m - 1, j});
        }
        
        // Perform breadth-first search to check the land cells
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int x = cell[0], y = cell[1];
            
            // Skip if the current cell is already marked as visited or is not a land cell
            if (grid[x][y]!= 1) continue;
            
            // Mark the current cell as visited
            grid[x][y] = 2;
            count++;
            
            // Add the coordinates of the adjacent land cells to the queue
            queue.offer(new int[]{x - 1, y});
            queue.offer(new int[]{x + 1, y});
            queue.offer(new int[]{x, y - 1});
            queue.offer(new int[]{x, y + 1});
        }
        
        // Return the number of land cells that cannot be walked off the boundary
        return m * n - count;
        
    }
}