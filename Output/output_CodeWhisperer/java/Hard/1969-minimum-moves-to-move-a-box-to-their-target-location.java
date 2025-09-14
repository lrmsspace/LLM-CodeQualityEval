/**https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/ */
//A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.
//The game is represented by an m x n grid of characters grid where each element is a wall, floor, or box.
//Your task is to move the box 'B' to the target position 'T' under the following rules:
//	The character 'S' represents the player. The player can move up, down, left, right in grid if it is a floor (empty cell).
//	The character '.' represents the floor which means a free cell to walk.
//	The character '#' represents the wall which means an obstacle (impossible to walk there).
//	There is only one box 'B' and one target cell 'T' in the grid.
//	The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
//	The player cannot walk through the box.
//Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.
// 
//Example 1:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T","#","#","#","#"],
//               ["#",".",".","B",".","#"],
//               ["#",".","#","#",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: 3
//Explanation: We return only the number of times the box is pushed.
//Example 2:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T","#","#","#","#"],
//               ["#",".",".","B",".","#"],
//               ["#","#","#","#",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: -1
//Example 3:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T",".",".","#","#"],
//               ["#",".","#","B",".","#"],
//               ["#",".",".",".",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: 5
//Explanation: push the box down, left, left, up and up.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 20
//	grid contains only characters '.', '#', 'S', 'T', or 'B'.
//	There is only one character 'S', 'B', and 'T' in the grid.
class Solution {
    // Directions: up, down, left, right
    private static final int[][] DIRS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    public int minPushBox(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        // Find initial positions of player (S), box (B) and target (T)
        int[] player = new int[2];
        int[] box = new int[2];
        int[] target = new int[2];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    player[0] = i;
                    player[1] = j;
                    grid[i][j] = '.';
                } else if (grid[i][j] == 'B') {
                    box[0] = i;
                    box[1] = j;
                    grid[i][j] = '.';
                } else if (grid[i][j] == 'T') {
                    target[0] = i;
                    target[1] = j;
                    grid[i][j] = '.';
                }
            }
        }
        
        // BFS queue to store box positions and player positions
        Queue<int[]> queue = new LinkedList<>();
        // visited[box_row][box_col][player_row][player_col]
        boolean[][][][] visited = new boolean[m][n][m][n];
        
        queue.offer(new int[]{box[0], box[1], player[0], player[1]});
        visited[box[0]][box[1]][player[0]][player[1]] = true;
        int pushes = 0;
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            
            for (int i = 0; i < size; i++) {
                int[] curr = queue.poll();
                int boxRow = curr[0], boxCol = curr[1];
                int playerRow = curr[2], playerCol = curr[3];
                
                // Check if box reached target
                if (boxRow == target[0] && boxCol == target[1]) {
                    return pushes;
                }
                
                // Try all four directions to push the box
                for (int[] dir : DIRS) {
                    int newBoxRow = boxRow + dir[0];
                    int newBoxCol = boxCol + dir[1];
                    int newPlayerRow = boxRow - dir[0];
                    int newPlayerCol = boxCol - dir[1];
                    
                    // Check if new positions are valid
                    if (!isValid(grid, newBoxRow, newBoxCol) || 
                        !isValid(grid, newPlayerRow, newPlayerCol)) {
                        continue;
                    }
                    
                    // Check if player can reach the pushing position
                    if (!canReachPosition(grid, playerRow, playerCol, 
                                       newPlayerRow, newPlayerCol, boxRow, boxCol)) {
                        continue;
                    }
                    
                    // If this state hasn't been visited
                    if (!visited[newBoxRow][newBoxCol][boxRow][boxCol]) {
                        visited[newBoxRow][newBoxCol][boxRow][boxCol] = true;
                        queue.offer(new int[]{newBoxRow, newBoxCol, boxRow, boxCol});
                    }
                }
            }
            pushes++;
        }
        
        return -1;
    }
    
    private boolean isValid(char[][] grid, int row, int col) {
        return row >= 0 && row < grid.length && col >= 0 && 
               col < grid[0].length && grid[row][col] != '#';
    }
    
    private boolean canReachPosition(char[][] grid, int startRow, int startCol, 
                                   int targetRow, int targetCol, int boxRow, int boxCol) {
        if (startRow == targetRow && startCol == targetCol) return true;
        
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        Queue<int[]> queue = new LinkedList<>();
        
        queue.offer(new int[]{startRow, startCol});
        visited[startRow][startCol] = true;
        
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            
            for (int[] dir : DIRS) {
                int newRow = curr[0] + dir[0];
                int newCol = curr[1] + dir[1];
                
                if (newRow == targetRow && newCol == targetCol) {
                    return true;
                }
                
                if (isValid(grid, newRow, newCol) && !visited[newRow][newCol] && 
                    (newRow != boxRow || newCol != boxCol)) {
                    visited[newRow][newCol] = true;
                    queue.offer(new int[]{newRow, newCol});
                }
            }
        }
        
        return false;
    }
}
