/**https://leetcode.com/problems/strange-printer-ii/ */
//There is a strange printer with the following two special requirements:
//	On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
//	Once the printer has used a color for the above operation, the same color cannot be used again.
//You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.
//Return true if it is possible to print the matrix targetGrid, otherwise, return false.
// 
//Example 1:
//Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
//Output: true
//Example 2:
//Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
//Output: true
//Example 3:
//Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
//Output: false
//Explanation: It is impossible to form targetGrid because it is not allowed to print the same color in different turns.
// 
//Constraints:
//	m == targetGrid.length
//	n == targetGrid[i].length
//	1 <= m, n <= 60
//	1 <= targetGrid[row][col] <= 60
bool isPrintable(int** targetGrid, int targetGridSize, int* targetGridColSize) {
    int m = targetGridSize;
    int n = targetGridColSize[0];
    int minRow[61] = {0};
    int maxRow[61] = {0};
    int minCol[61] = {0};
    int maxCol[61] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int color = targetGrid[i][j];
            if (minRow[color] == 0) {
                minRow[color] = i + 1;
                maxRow[color] = i + 1;
                minCol[color] = j + 1;
                maxCol[color] = j + 1;
            } else {
                minRow[color] = fmin(minRow[color], i + 1);
                maxRow[color] = fmax(maxRow[color], i + 1);
                minCol[color] = fmin(minCol[color], j + 1);
                maxCol[color] = fmax(maxCol[color], j + 1);
            }
        }
    }
    for (int color = 1; color <= 60; color++) {
        if (minRow[color] == 0) {
            continue;
        }
        for (int i = minRow[color] - 1; i < maxRow[color]; i++) {
            for (int j = minCol[color] - 1; j < maxCol[color]; j++) {
                if (targetGrid[i][j] > 0 && targetGrid[i][j] != color) {
                    for (int k = minRow[targetGrid[i][j]] - 1; k < maxRow[targetGrid[i][j]]; k++) {
                        for (int l = minCol[targetGrid[i][j]] - 1; l < maxCol[targetGrid[i][j]]; l++) {
                            if (targetGrid[k][l] == color) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        for (int i = minRow[color] - 1; i < maxRow[color]; i++) {
            for (int j = minCol[color] - 1; j < maxCol[color]; j++) {
                targetGrid[i][j] = 0;
            }
        }
    }
    return true;
}