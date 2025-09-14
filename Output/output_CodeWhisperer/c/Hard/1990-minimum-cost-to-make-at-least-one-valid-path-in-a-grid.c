/**https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/ */
//Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:
//	1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
//	2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
//	3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
//	4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
//Notice that there could be some signs on the cells of the grid that point outside the grid.
//You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.
//You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.
//Return the minimum cost to make the grid have at least one valid path.
// 
//Example 1:
//Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
//Output: 3
//Explanation: You will start at point (0, 0).
//The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
//The total cost = 3.
//Example 2:
//Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
//Output: 0
//Explanation: You can follow the path from (0, 0) to (2, 2).
//Example 3:
//Input: grid = [[1,2],[4,3]]
//Output: 1
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 100
//	1 <= grid[i][j] <= 4
int minCost(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    // Initialize distance array with infinity
    int** dist = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dist[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    
    // Directions: right, left, down, up (matching the grid values 1, 2, 3, 4)
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    
    // Create deque for 0-1 BFS
    Deque* deque = createDeque();
    
    // Start from the top-left cell
    dist[0][0] = 0;
    Cell start = {0, 0, 0};
    addFront(deque, start);
    
    while (!isEmpty(deque)) {
        Cell current = removeFront(deque);
        int row = current.row;
        int col = current.col;
        int cost = current.cost;
        
        // If we've reached the bottom-right cell, we're done
        if (row == m - 1 && col == n - 1) {
            // Free memory
            for (int i = 0; i < m; i++) {
                free(dist[i]);
            }
            free(dist);
            freeDeque(deque);
            
            return cost;
        }
        
        // Skip if we've found a better path already
        if (cost > dist[row][col]) continue;
        
        // Try all four directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            
            // Check if the new position is valid
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                // Calculate the cost to move to the new cell
                int newCost = cost;
                
                // If the sign doesn't point to the direction we want to go, add 1 to the cost
                if (grid[row][col] != i + 1) {
                    newCost++;
                }
                
                // Update distance if we found a shorter path
                if (newCost < dist[newRow][newCol]) {
                    dist[newRow][newCol] = newCost;
                    Cell newCell = {newRow, newCol, newCost};
                    
                    // Add to front if cost is same (following sign), add to rear if cost increased (changing sign)
                    if (grid[row][col] == i + 1) {
                        addFront(deque, newCell);
                    } else {
                        addRear(deque, newCell);
                    }
                }
            }
        }
    }
    
    // Free memory
    for (int i = 0; i < m; i++) {
        free(dist[i]);
    }
    free(dist);
    freeDeque(deque);
    
    // No valid path found (shouldn't happen given the constraints)
    return -1;  
}