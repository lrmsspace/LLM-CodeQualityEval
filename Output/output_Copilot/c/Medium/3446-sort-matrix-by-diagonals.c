/*
 You are given an n x n square matrix of integers grid. Return the matrix such that:
 The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
 The diagonals in the top-right triangle are sorted in non-decreasing order.
 Example 1:
 Input: grid = [[1,7,3],[9,8,2],[4,5,6]]
 Output: [[8,2,3],[9,6,7],[4,5,1]]
 Explanation:
 The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:
 [1, 8, 6] becomes [8, 6, 1].
 [9, 5] and [4] remain unchanged.
 The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:
 [7, 2] becomes [2, 7].
 [3] remains unchanged.
 Example 2:
 Input: grid = [[0,1],[1,2]]
 Output: [[2,1],[1,0]]
 Explanation:
 The diagonals with a black arrow must be non-increasing, so [0, 2] is changed to [2, 0]. The other diagonals are already in the correct order.
 Example 3:
 Input: grid = [[1]]
 Output: [[1]]
 Explanation:
 Diagonals with exactly one element are already in order, so no changes are needed.
 Constraints:
 grid.length == grid[i].length == n
 1 <= n <= 10
 -105 <= grid[i][j] <= 105
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** sortMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int n = gridSize;
    int** result = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
    }
    
    // Sort bottom-left diagonals
    for (int d = 0; d < n; d++) {
        int size = d + 1;
        int* diag = (int*)malloc(size * sizeof(int));
        for (int i = 0; i <= d; i++) {
            diag[i] = grid[d - i][i];
        }
        qsort(diag, size, sizeof(int), (__compar_fn_t)compare);
        for (int i = 0; i <= d; i++) {
            result[d - i][i] = diag[i];
        }
        free(diag);
    }
    
    // Sort top-right diagonals
    for (int d = 1; d < n; d++) {
        int size = n - d;
        int* diag = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            diag[i] = grid[i][d + i];
        }
        qsort(diag, size, sizeof(int), (__compar_fn_t)compare);
        for (int i = 0; i < size; i++) {
            result[i][d + i] = diag[i];
        }
        free(diag);
    }
    
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }
    
    return result;    
}