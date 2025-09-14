/*
 You are given a 0-indexed n x n grid where n is odd, and grid[r][c] is 0, 1, or 2.
 We say that a cell belongs to the Letter Y if it belongs to one of the following:
 The diagonal starting at the top-left cell and ending at the center cell of the grid.
 The diagonal starting at the top-right cell and ending at the center cell of the grid.
 The vertical line starting at the center cell and ending at the bottom border of the grid.
 The Letter Y is written on the grid if and only if:
 All values at cells belonging to the Y are equal.
 All values at cells not belonging to the Y are equal.
 The values at cells belonging to the Y are different from the values at cells not belonging to the Y.
 Return the minimum number of operations needed to write the letter Y on the grid given that in one operation you can change the value at any cell to 0, 1, or 2.
 Example 1:
 Input: grid = [[1,2,2],[1,1,0],[0,1,0]]
 Output: 3
 Explanation: We can write Y on the grid by applying the changes highlighted in blue in the image above. After the operations, all cells that belong to Y, denoted in bold, have the same value of 1 while those that do not belong to Y are equal to 0.
 It can be shown that 3 is the minimum number of operations needed to write Y on the grid.
 Example 2:
 Input: grid = [[0,1,0,1,0],[2,1,0,1,2],[2,2,2,0,1],[2,2,2,2,2],[2,1,2,2,2]]
 Output: 12
 Explanation: We can write Y on the grid by applying the changes highlighted in blue in the image above. After the operations, all cells that belong to Y, denoted in bold, have the same value of 0 while those that do not belong to Y are equal to 2. 
 It can be shown that 12 is the minimum number of operations needed to write Y on the grid.
 Constraints:
 3 <= n <= 49 
 n == grid.length == grid[i].length
 0 <= grid[i][j] <= 2
 n is odd.
*/

int minimumOperationsToWriteY(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int center = n / 2;
    int yValue = -1;
    int nonYValue = -1;

    // Count the occurrences of each value in the Y region and non-Y region
    int yCount[3] = {0};  // Count for values 0, 1, 2 in Y region
    int nonYCount[3] = {0};  // Count for values 0, 1, 2 in non-Y region

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && i <= center) {
                // Diagonal from top-left to center
                yCount[grid[i][j]]++;
            } else if (i + j == n - 1 && i <= center) {
                // Diagonal from top-right to center
                yCount[grid[i][j]]++;
            } else if (i == center) {
                // Vertical line from center to bottom
                yCount[grid[i][j]]++;
            } else {
                // Non-Y region
                nonYCount[grid[i][j]]++;
            }
        }
    }

    // Find the most common value in the Y region
    for (int i = 0; i < 3; i++) {
        if (yCount[i] > yCount[yValue]) {
            yValue = i;
        }
    }

    // Find the most common value in the non-Y region
    for (int i = 0; i < 3; i++) {
        if (nonYCount[i] > nonYCount[nonYValue]) {
            nonYValue = i;
        }
    }

    // If the most common values are the same, we need to change one of them
    if (yValue == nonYValue) {
        int yChanges = yCount[yValue] - 1;
        int nonYChanges = nonYCount[nonYValue] - 1;
        return yChanges + nonYChanges + 1;
    }

    // Otherwise, we can change all Y cells to the most common non-Y value
    return nonYCount[nonYValue] + (yCount[yValue] - 1);
}