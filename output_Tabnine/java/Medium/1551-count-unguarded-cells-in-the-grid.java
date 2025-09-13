/**https://leetcode.com/problems/count-unguarded-cells-in-the-grid/ */
//You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
//A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.
//Return the number of unoccupied cells that are not guarded.
// 
//Example 1:
//Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
//Output: 7
//Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
//There are a total of 7 unguarded cells, so we return 7.
//Example 2:
//Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
//Output: 4
//Explanation: The unguarded cells are shown in green in the above diagram.
//There are a total of 4 unguarded cells, so we return 4.
// 
//Constraints:
//	1 <= m, n <= 105
//	2 <= m * n <= 105
//	1 <= guards.length, walls.length <= 5 * 104
//	2 <= guards.length + walls.length <= m * n
//	guards[i].length == walls[j].length == 2
//	0 <= rowi, rowj < m
//	0 <= coli, colj < n
//	All the positions in guards and walls are unique.
class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        // Initialize a boolean matrix to keep track of whether a cell is guarded or not
        boolean[][] isGuarded = new boolean[m][n];
        
        // Initialize a boolean matrix to keep track of whether a cell is a wall or not
        boolean[][] isWall = new boolean[m][n];
        
        // Mark the cells that are guarded by guards as guarded
        for (int[] guard : guards) {
            isGuarded[guard[0]][guard[1]] = true;
        }
        
        // Mark the cells that are walls as walls
        for (int[] wall : walls) {
            isWall[wall[0]][wall[1]] = true;
        }
        
        // Initialize a queue to perform BFS
        Queue<int[]> queue = new LinkedList<>();
        
        // Add the cells that are guarded to the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isGuarded[i][j]) {
                    queue.offer(new int[]{i, j});
                }
            }
        }
        
        // Perform BFS to mark the cells that are guarded by walls
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int row = cell[0];
            int col = cell[1];
            
            // Mark the neighboring cells as guarded if they are walls
            for (int[] dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && isWall[newRow][newCol]) {
                    isGuarded[newRow][newCol] = true;
                    queue.offer(new int[]{newRow, newCol});
                }
            }
        }
        
        // Count the unoccupied cells that are not guarded
        int unguardedCells = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!isGuarded[i][j]) {
                    unguardedCells++;
                }
            }
        }
        
        return unguardedCells;
        
    }
}