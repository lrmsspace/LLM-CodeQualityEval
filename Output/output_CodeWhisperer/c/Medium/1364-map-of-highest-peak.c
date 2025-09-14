/**https://leetcode.com/problems/map-of-highest-peak/ */
//You are given an integer matrix isWater of size m x n that represents a map of land and water cells.
//	If isWater[i][j] == 0, cell (i, j) is a land cell.
//	If isWater[i][j] == 1, cell (i, j) is a water cell.
//You must assign each cell a height in a way that follows these rules:
//	The height of each cell must be non-negative.
//	If the cell is a water cell, its height must be 0.
//	Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
//Find an assignment of heights such that the maximum height in the matrix is maximized.
//Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.
// 
//Example 1:
//Input: isWater = [[0,1],[0,0]]
//Output: [[1,0],[2,1]]
//Explanation: The image shows the assigned heights of each cell.
//The blue cell is the water cell, and the green cells are the land cells.
//Example 2:
//Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
//Output: [[1,1,0],[0,1,1],[1,2,2]]
//Explanation: A height of 2 is the maximum possible height of any assignment.
//Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.
// 
//Constraints:
//	m == isWater.length
//	n == isWater[i].length
//	1 <= m, n <= 1000
//	isWater[i][j] is 0 or 1.
//	There is at least one water cell.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */ 
int** highestPeak(int** isWater, int isWaterSize, int* isWaterColSize, int* returnSize, int** returnColumnSizes) {
    int m = isWaterSize;
    int n = isWaterColSize[0];
    
    // Initialize the result matrix with -1 (unvisited)
    int** height = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    
    for (int i = 0; i < m; i++) {
        height[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            height[i][j] = -1;
        }
    }
    
    *returnSize = m;
    
    // Create a queue for BFS
    Cell* queue = (Cell*)malloc(m * n * sizeof(Cell));
    int front = 0, rear = 0;
    
    // Initialize the queue with all water cells (height 0)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isWater[i][j] == 1) {
                height[i][j] = 0;
                queue[rear++] = (Cell){i, j};
            }
        }
    }
    
    // Direction arrays for 4-directional movement
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    // BFS to assign heights
    while (front < rear) {
        Cell current = queue[front++];
        int r = current.row;
        int c = current.col;
        
        // Check all 4 adjacent cells
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // Check if the adjacent cell is within bounds and unvisited
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && height[nr][nc] == -1) {
                // Assign height 1 more than the current cell
                height[nr][nc] = height[r][c] + 1;
                queue[rear++] = (Cell){nr, nc};
            }
        }
    }
    
    free(queue);
    return height;
}
