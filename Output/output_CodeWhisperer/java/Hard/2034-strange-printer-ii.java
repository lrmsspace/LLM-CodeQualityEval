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
import java.util.Arrays;
class Solution {
    public boolean isPrintable(int[][] targetGrid) {
        int m = targetGrid.length, n = targetGrid[0].length;
        int[] minRow = new int[61], minCol = new int[61], maxRow = new int[61], maxCol = new int[61];
        Arrays.fill(minRow, m); Arrays.fill(minCol, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int c = targetGrid[i][j];
                minRow[c] = Math.min(minRow[c], i);
                minCol[c] = Math.min(minCol[c], j);
                maxRow[c] = Math.max(maxRow[c], i);
                maxCol[c] = Math.max(maxCol[c], j);
            }
        }
        
        int[][] grid = new int[m][n];
        for (int c = 60; c >= 1; c--) {
            if (minRow[c] == m) continue;
            boolean ok = true;
            for (int i = minRow[c]; i <= maxRow[c]; i++) {
                for (int j = minCol[c]; j <= maxCol[c]; j++) {
                    if (targetGrid[i][j] > 0 && grid[i][j] > 0) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (!ok) return false;
            for (int i = minRow[c]; i <= maxRow[c]; i++) {
                for (int j = minCol[c]; j <= maxCol[c]; j++) {
                    grid[i][j] = c;
                }
            }
        }
        return true;     
    }
}