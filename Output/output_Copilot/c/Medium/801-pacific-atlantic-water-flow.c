/**https://leetcode.com/problems/pacific-atlantic-water-flow/ */
//There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
//The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
//The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
//Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
// 
//Example 1:
//Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
//Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
//Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
//[0,4]: [0,4] -> Pacific Ocean 
//       [0,4] -> Atlantic Ocean
//[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
//       [1,3] -> [1,4] -> Atlantic Ocean
//[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
//       [1,4] -> Atlantic Ocean
//[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
//       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
//[3,0]: [3,0] -> Pacific Ocean 
//       [3,0] -> [4,0] -> Atlantic Ocean
//[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
//       [3,1] -> [4,1] -> Atlantic Ocean
//[4,0]: [4,0] -> Pacific Ocean 
//       [4,0] -> Atlantic Ocean
//Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
//Example 2:
//Input: heights = [[1]]
//Output: [[0,0]]
//Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
// 
//Constraints:
//	m == heights.length
//	n == heights[r].length
//	1 <= m, n <= 200
//	0 <= heights[r][c] <= 105
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {

    // Check if a cell is valid
    int isValid(int row, int col) {
        return row >= 0 && row < heightsSize && col >= 0 && col < heightsColSize[0];
    }

    // Initialize variables
    int** result = (int**)malloc(10000 * sizeof(int*));
    *returnSize = 0;
    int* pathLengths = (int*)malloc(10000 * sizeof(int));
    int* path = (int*)malloc(10000 * sizeof(int));
    int** visitedPacific = (int**)malloc(heightsSize * sizeof(int*));
    int** visitedAtlantic = (int**)malloc(heightsSize * sizeof(int*));
    for (int i = 0; i < heightsSize; i++) {
        visitedPacific[i] = (int*)malloc(heightsColSize[0] * sizeof(int));
        visitedAtlantic[i] = (int*)malloc(heightsColSize[0] * sizeof(int));
        for (int j = 0; j < heightsColSize[0]; j++) {
            visitedPacific[i][j] = 0;
            visitedAtlantic[i][j] = 0;
        }
    }
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Find all cells that can flow to both oceans
    for (int i = 0; i < heightsSize; i++) {
        for (int j = 0; j < heightsColSize[0]; j++) {
            path[0] = i * heightsColSize[0] + j;
            pathLengths[0] = 1;
            visitedPacific[i][j] = 1;
            visitedAtlantic[i][j] = 1;
            for (int k = 0; k < pathLengths[0]; k++) {
                int row = path[k] / heightsColSize[0];
                int col = path[k] % heightsColSize[0];
                for (int l = 0; l < 4; l++) {
                    int newRow = row + directions[l][0];
                    int newCol = col + directions[l][1];
                    if (isValid(newRow, newCol) && !visitedPacific[newRow][newCol] && heights[newRow][newCol    ] >= heights[row][col]) {
                        visitedPacific[newRow][newCol] = 1;
                        path[pathLengths[0]++] = newRow * heightsColSize[0] + newCol;
                    }

                    newRow = row + directions[l][0];
                    newCol = col + directions[l][1];
                    if (isValid(newRow, newCol) && !visitedAtlantic[newRow][newCol] && heights[newRow][newCol] >= heights[row][col]) {
                        visitedAtlantic[newRow][newCol] = 1;
                        path[pathLengths[0]++] = newRow * heightsColSize[0] + newCol;
                    }
                }
            }
        }

        // Check if a cell can flow to both oceans
        for (int i = 0; i < heightsSize; i++) {
            for (int j = 0; j < heightsColSize[0]; j++) {
                if (visitedPacific[i][j] && visitedAtlantic[i][j]) {
                    result[*returnSize] = (int*)malloc(2 * sizeof(int));
                    result[*returnSize][0] = i;
                    result[*returnSize][1] = j;
                    (*returnSize)++;
                }
            }
        }
        
        // Return result
        *returnColumnSizes = pathLengths;
        return result;

}