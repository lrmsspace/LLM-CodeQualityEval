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
class Solution {
    public boolean isPrintable(int[][] targetGrid) {
        int m = targetGrid.length, n = targetGrid[0].length;
        int[][] bounds = new int[61][4];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int color = targetGrid[i][j];
                bounds[color][0] = Math.min(bounds[color][0], j);
                bounds[color][1] = Math.min(bounds[color][1], i);
                bounds[color][2] = Math.max(bounds[color][2], j);
                bounds[color][3] = Math.max(bounds[color][3], i);
            }
        }    
        for (int color = 1; color <= 100; color++) {
            if (bounds[color][0] > bounds[color][2] || bounds[color][1] > bounds[color][3]) continue;
            int row = bounds[color][3] - bounds[color][1] + 1;
            int col = bounds[color][2] - bounds[color][0] + 1;
            int[][] subGrid = new int[row][col];
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    subGrid[i][j] = targetGrid[bounds[color][1] + i][bounds[color][0] + j];
                }
            }
        }
        return true;
    }
}