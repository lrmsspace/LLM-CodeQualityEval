/**https://leetcode.com/problems/as-far-from-land-as-possible/ */
//Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.
//The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
// 
//Example 1:
//Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
//Output: 2
//Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
//Example 2:
//Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
//Output: 4
//Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 100
//	grid[i][j] is 0 or 1
class Solution {
    public int maxDistance(int[][] grid) {
        if(grid == null || grid.length == 0 || grid[0].length == 0) return -1;
        int n = grid.length;
        int maxDistance = 0;
        
        // Step 1: Initialize a queue to store the coordinates of water cells.
        Queue<int[]> queue = new LinkedList<>();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    queue.offer(new int[]{i, j});
                }
            }
        }
        
        // Step 2: Perform BFS to find the maximum distance from each water cell to the nearest land cell.
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!queue.isEmpty()) {
            int size = queue.size();
            for(int k = 0; k < size; k++) {
                int[] cell = queue.poll();
                int x = cell[0];
                int y = cell[1];
                
                for(int[] dir : directions) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];
                    
                    if(newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                        grid[newX][newY] = grid[x][y] + 1;
                        maxDistance = Math.max(maxDistance, grid[newX][newY]);
                        queue.offer(new int[]{newX, newY});
                    }
                }
            }
        }
        
        return maxDistance == Integer.MAX_VALUE? -1 : maxDistance;
        
    }
}