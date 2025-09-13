/**https://leetcode.com/problems/cyclically-rotating-a-grid/ */
//You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.
//The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:
//A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:
//Return the matrix after applying k cyclic rotations to it.
// 
//Example 1:
//Input: grid = [[40,10],[30,20]], k = 1
//Output: [[10,20],[40,30]]
//Explanation: The figures above represent the grid at every state.
//Example 2:
//  
//Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
//Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
//Explanation: The figures above represent the grid at every state.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	2 <= m, n <= 50
//	Both m and n are even integers.
//	1 <= grid[i][j] <= 5000
//	1 <= k <= 109
/**

 * Return an array of arrays of size *returnSize.

 * The sizes of the arrays are returned as *returnColumnSizes array.

 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().

 */

int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    // Initialize returnSize and returnColumnSizes
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    
    // Create a new 2D array to store the rotated grid
    int** rotatedGrid = malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        rotatedGrid[i] = malloc(gridColSize[i] * sizeof(int));
    }
    
    // Perform the cyclic rotations
    for (int layer = 0; layer < gridSize / 2; layer++) {
        int start = layer;
        int end = gridSize - 1 - layer;
        
        // Rotate each row within the layer
        for (int i = start; i < end; i++) {
            int temp = rotatedGrid[start][i];
            
            // Rotate each element in the row
            for (int j = start; j < end; j++) {
                rotatedGrid[start][j] = rotatedGrid[end - j + start][start];
            }
            
            rotatedGrid[start][end] = temp;
        }
        
        // Rotate each column within the layer
        for (int i = start + 1; i < end; i++) {
            int temp = rotatedGrid[i][end];
            
            // Rotate each element in the column
            for (int j = end; j > start; j--) {
                rotatedGrid[j][end] = rotatedGrid[j - 1][end];
            }
            
            rotatedGrid[end][start] = temp;
        }
        
        // Rotate the diagonal elements within the layer
        for (int i = start, j = start; i < end; i++, j++) {
            int temp = rotatedGrid[i][j];
            rotatedGrid[i][j] = rotatedGrid[end - j + start][end - i + start];
            rotatedGrid[end - j + start][end - i + start] = temp;
        }
    }
    
    // Return the rotated grid
    return rotatedGrid;

}