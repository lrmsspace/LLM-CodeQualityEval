/*
 You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:
 Each of the two resulting sections formed by the cut is non-empty.
 The sum of the elements in both sections is equal.
 Return true if such a partition exists; otherwise return false.
 Example 1:
 Input: grid = [[1,4],[2,3]]
 Output: true
 Explanation:
 A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.
 Example 2:
 Input: grid = [[1,3],[2,4]]
 Output: false
 Explanation:
 No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.
 Constraints:
 1 <= m == grid.length <= 105
 1 <= n == grid[i].length <= 105
 2 <= m * n <= 105
 1 <= grid[i][j] <= 105
*/

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int totalSum = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            totalSum += grid[i][j];
        }
    }

    // If the total sum is odd, we cannot partition it into two equal parts
    if (totalSum % 2 != 0) {
        return false;
    }

    int target = totalSum / 2;

    // Check for horizontal cuts
    int* rowSums = (int*)malloc(gridSize * sizeof(int));
    for (int i = 0; i < gridSize; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < gridColSize[i]; j++) {
            rowSums[i] += grid[i][j];
        }
    }

    int currentSum = 0;
    for (int i = 0; i < gridSize - 1; i++) {
        currentSum += rowSums[i];
        if (currentSum == target) {
            free(rowSums);
            return true;
        }
    }

    // Check for vertical cuts
    int* colSums = (int*)malloc(gridColSize[0] * sizeof(int));
    for (int j = 0; j < gridColSize[0]; j++) {
        colSums[j] = 0;
        for (int i = 0; i < gridSize; i++) {
            colSums[j] += grid[i][j];
        }
    }

    currentSum = 0;
    for (int j = 0; j < gridColSize[0] - 1; j++) {
        currentSum += colSums[j];
        if (currentSum == target) {
            free(rowSums);
            free(colSums);
            return true;
        }
    }

    free(rowSums);
    free(colSums);
    return false;
}