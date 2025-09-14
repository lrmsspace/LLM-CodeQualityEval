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

class Solution {
    public int minimumOperationsToWriteY(int[][] grid) {
        int n = grid.length;
        int mid = n / 2;
        int[] countY = new int[3]; // Count of values in Y
        int[] countNotY = new int[3]; // Count of values not in Y

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (c == mid || r + c == mid || r - c == mid) { // Check if cell belongs to Y
                    countY[grid[r][c]]++;
                } else {
                    countNotY[grid[r][c]]++;
                }
            }
        }

        // Find the minimum operations needed to make all Y cells the same and all non-Y cells the same
        int minOps = Integer.MAX_VALUE;

        for (int yValue = 0; yValue < 3; yValue++) {
            for (int notYValue = 0; notYValue < 3; notYValue++) {
                if (yValue != notYValue) {
                    int ops = (countY[0] + countY[1] + countY[2] - countY[yValue]) +
                              (countNotY[0] + countNotY[1] + countNotY[2] - countNotY[notYValue]);
                    minOps = Math.min(minOps, ops);
                }
            }
        }

        return minOps;        
    }
}