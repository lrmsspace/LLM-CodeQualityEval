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
int compareAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int** sortMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = gridSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        (*returnColumnSizes)[i] = gridColSize[i];
    }

    for (int d = 0; d < gridSize; d++) {
        // Sort bottom-left diagonals (including middle) in non-increasing order
        int len = gridSize - d;
        int* diagonal = (int*)malloc(sizeof(int) * len);
        for (int i = 0; i < len; i++) {
            diagonal[i] = grid[d + i][i];
        }
        qsort(diagonal, len, sizeof(int), compareDesc);
        for (int i = 0; i < len; i++) {
            grid[d + i][i] = diagonal[i];
        }
        free(diagonal);
    }

    for (int d = 1; d < gridSize; d++) {
        // Sort top-right diagonals in non-decreasing order
        int len = gridSize - d;
        int* diagonal = (int*)malloc(sizeof(int) * len);
        for (int i = 0; i < len; i++) {
            diagonal[i] = grid[i][d + i];
        }
        qsort(diagonal, len, sizeof(int), compareAsc);
        for (int i = 0; i < len; i++) {
            grid[i][d + i] = diagonal[i];
        }
        free(diagonal);
    }

    return grid;
}

