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
int minPushBox(char** grid, int gridSize, int* gridColSize) {   
        // Find initial positions of box, player, and target
        int boxRow, boxCol, playerRow, playerCol, targetRow, targetCol;
    
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridColSize[i]; j++) {
                if (grid[i][j] == 'B') {
                    boxRow = i;
                    boxCol = j;
                    grid[i][j] = '.'; // Temporarily mark as floor for easier processing
                } else if (grid[i][j] == 'S') {
                    playerRow = i;
                    playerCol = j;
                    grid[i][j] = '.'; // Temporarily mark as floor for easier processing
                } else if (grid[i][j] == 'T') {
                    targetRow = i;
                    targetCol = j;
                }
            }
        }
        
        // BFS to find minimum pushes
        Queue* queue = createQueue(gridSize * gridColSize[0] * gridSize * gridColSize[0]);
        State start = {boxRow, boxCol, playerRow, playerCol, 0};
        enqueue(queue, start);
        
        // Use a hash set to track visited states
        int maxStates = gridSize * gridColSize[0] * gridSize * gridColSize[0];
        bool* visited = (bool*)calloc(maxStates, sizeof(bool));
        
        int hash = hashState(boxRow, boxCol, playerRow, playerCol, gridSize, gridColSize[0]);
        visited[hash] = true;
        
        // Directions: up, right, down, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while (!isEmpty(queue)) {
            State current = dequeue(queue);
            
            // Check if box is at target
            if (current.boxRow == targetRow && current.boxCol == targetCol) {
                // Restore original grid
                grid[boxRow][boxCol] = 'B';
                grid[playerRow][playerCol] = 'S';
                
                // Free memory
                free(visited);
                freeQueue(queue);
                
                return current.pushes;
            }
            
            // Try to push the box in all four directions
            for (int i = 0; i < 4; i++) {
                int newBoxRow = current.boxRow + dr[i];
                int newBoxCol = current.boxCol + dc[i];
                
                // Position the player needs to be at to push the box
                int requiredPlayerRow = current.boxRow - dr[i];
                int requiredPlayerCol = current.boxCol - dc[i];
                
                // Check if the new box position is valid
                if (newBoxRow >= 0 && newBoxRow < gridSize && 
                    newBoxCol >= 0 && newBoxCol < gridColSize[0] && 
                    grid[newBoxRow][newBoxCol] != '#' && 
                    requiredPlayerRow >= 0 && requiredPlayerRow < gridSize && 
                    requiredPlayerCol >= 0 && requiredPlayerCol < gridColSize[0] && 
                    grid[requiredPlayerRow][requiredPlayerCol] != '#') {
                    
                    // Check if this state has been visited
                    int newHash = hashState(newBoxRow, newBoxCol, current.boxRow, current.boxCol, gridSize, gridColSize[0]);
                    if (!visited[newHash]) {
                        // Check if player can reach the required position
                        if (canPlayerReach(grid, gridSize, gridColSize, 
                                          current.playerRow, current.playerCol, 
                                          requiredPlayerRow, requiredPlayerCol, 
                                          current.boxRow, current.boxCol)) {
                            
                            visited[newHash] = true;
                            State newState = {newBoxRow, newBoxCol, current.boxRow, current.boxCol, current.pushes + 1};
                            enqueue(queue, newState);
                        }
                    }
                }
            }
        }
        
        // Restore original grid
        grid[boxRow][boxCol] = 'B';
        grid[playerRow][playerCol] = 'S';
        
        // Free memory
        free(visited);
        freeQueue(queue);
        
        // No solution found
        return -1;  
}