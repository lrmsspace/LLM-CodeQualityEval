/**https://leetcode.com/problems/largest-local-values-in-a-matrix/ */
//You are given an n x n integer matrix grid.
//Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:
//	maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
//In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.
//Return the generated matrix.
// 
//Example 1:
//Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
//Output: [[9,9],[8,6]]
//Explanation: The diagram above shows the original matrix and the generated matrix.
//Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.
//Example 2:
//Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
//Output: [[2,2,2],[2,2,2],[2,2,2]]
//Explanation: Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.
// 
//Constraints:
//	n == grid.length == grid[i].length
//	3 <= n <= 100
//	1 <= grid[i][j] <= 100
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes){
    int i, j, k, l, max, row, col;
    int** result;
    *returnSize = gridSize - 2;
    row = *returnSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * row);
    result = (int**)malloc(sizeof(int*) * row);
    for (i = 0; i < row; i++) {
        result[i] = (int*)malloc(sizeof(int) * row);
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < row; j++) {
            max = 0;
            for (k = i; k < i + 3; k++) {
                for (l = j; l < j + 3; l++) {
                    if (grid[k][l] > max) {
                        max = grid[k][l];
                    }
                }
            }
        }
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < row; j++) {
            result[i][j] = max;
        }
    }   
    return result;
}