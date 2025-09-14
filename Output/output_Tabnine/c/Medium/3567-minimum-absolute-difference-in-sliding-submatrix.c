/*
 You are given an m x n integer matrix grid and an integer k.
 For every contiguous k x k submatrix of grid, compute the minimum absolute difference between any two distinct values within that submatrix.
 Return a 2D array ans of size (m - k + 1) x (n - k + 1), where ans[i][j] is the minimum absolute difference in the submatrix whose top-left corner is (i, j) in grid.
 Note: If all elements in the submatrix have the same value, the answer will be 0.
 A submatrix (x1, y1, x2, y2) is a matrix that is formed by choosing all cells matrix[x][y] where x1 <= x <= x2 and y1 <= y <= y2.
 Example 1:
 Input: grid = [[1,8],[3,-2]], k = 2
 Output: [[2]]
 Explanation:
 There is only one possible k x k submatrix: [[1, 8], [3, -2]].
 Distinct values in the submatrix are [1, 8, 3, -2].
 The minimum absolute difference in the submatrix is |1 - 3| = 2. Thus, the answer is [[2]].
 Example 2:
 Input: grid = [[3,-1]], k = 1
 Output: [[0,0]]
 Explanation:
 Both k x k submatrix has only one distinct element.
 Thus, the answer is [[0, 0]].
 Example 3:
 Input: grid = [[1,-2,3],[2,3,5]], k = 2
 Output: [[1,2]]
 Explanation:
 There are two possible k × k submatrix:
 Starting at (0, 0): [[1, -2], [2, 3]].
 Distinct values in the submatrix are [1, -2, 2, 3].
 The minimum absolute difference in the submatrix is |1 - 2| = 1.
 Starting at (0, 1): [[-2, 3], [3, 5]].
 Distinct values in the submatrix are [-2, 3, 5].
 The minimum absolute difference in the submatrix is |3 - 5| = 2.
 Thus, the answer is [[1, 2]].
 Constraints:
 1 <= m == grid.length <= 30
 1 <= n == grid[i].length <= 30
 -105 <= grid[i][j] <= 105
 1 <= k <= min(m, n)
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int minAbsoluteDifference(int* submatrix, int submatrixSize) {
    int minDiff = INT_MAX;
    for (int i = 0; i < submatrixSize; i++) {
        for (int j = i + 1; j < submatrixSize; j++) {
            int diff = abs(submatrix[i] - submatrix[j]);
            if (diff < minDiff) {
                minDiff = diff;
            }
        }
    }
    return minDiff;
}

int** minAbsDiff(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = (gridSize - k + 1) * (gridColSize[0] - k + 1);
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    int** result = (int**)malloc((*returnSize) * sizeof(int*));

    int index = 0;
    for (int i = 0; i <= gridSize - k; i++) {
        (*returnColumnSizes)[index] = gridColSize[0] - k + 1;
        result[index] = (int*)malloc((*returnColumnSizes)[index] * sizeof(int));

        for (int j = 0; j <= gridColSize[0] - k; j++) {
            int* submatrix = (int*)malloc(k * k * sizeof(int));
            int submatrixIndex = 0;
            for (int x = i; x < i + k; x++) {
                for (int y = j; y < j + k; y++) {
                    submatrix[submatrixIndex++] = grid[x][y];
                }
            }
            result[index][j] = minAbsoluteDifference(submatrix, k * k);
            free(submatrix);
        }
        index++;
    }

    return result;
}