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
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = gridSize - 2;
    int** maxLocal = (int**)malloc((*returnSize) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < *returnSize; ++i) {
        maxLocal[i] = (int*)malloc((*returnSize) * sizeof(int));
        (*returnColumnSizes)[i] = *returnSize;
        for (int j = 0; j < *returnSize; ++j) {
            int maxVal = 0;
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    if (grid[i + x][j + y] > maxVal) {
                        maxVal = grid[i + x][j + y];
                    }
                }
            }
            maxLocal[i][j] = maxVal;
        }
    }

    return maxLocal;

}