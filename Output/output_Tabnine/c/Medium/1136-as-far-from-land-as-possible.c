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
int maxDistance(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int maxDistance = 0;
    
    // Initialize a visited matrix
    int** visited = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        visited[i] = (int*)calloc(gridColSize[i], sizeof(int));
    }
    
    // Perform breadth-first search (BFS) to find the maximum distance from each water cell
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 0) {
                int distance = bfs(grid, n, gridColSize, visited, i, j);
                maxDistance = max(maxDistance, distance);
            }
        }
    }
    
    // Free the visited matrix
    for (int i = 0; i < n; i++) {
        free(visited[i]);
    }
    free(visited);
    
    return maxDistance == 0? -1 : maxDistance;
    
}