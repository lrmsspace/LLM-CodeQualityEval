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
        int[][] color = new int[61][4];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int c = targetGrid[i][j];
                if (color[c][0] == 0) {
                    color[c][0] = i + 1;
                    color[c][1] = j + 1;
                } else {
                    color[c][2] = Math.max(color[c][2], i + 1);
                    color[c][3] = Math.max(color[c][3], j + 1);
                }
            }
        }
        boolean[] visited = new boolean[61];
        while (true) {
            boolean found = false;
            for (int c = 1; c <= 60; c++) {
                if (!visited[c] && color[c][0] > 0) {
                    found = true;
                    visited[c] = true;
                    for (int i = color[c][0]; i <= color[c][2]; i++) {
                        for (int j = color[c][1]; j <= color[c][3]; j++) {
                            if (targetGrid[i - 1][j - 1] != c) {
                                return false;
                            }
                        }
                    }
                    for (int i = color[c][0]; i <= color[c][2]; i++) {
                        for (int j = color[c][1]; j <= color[c][3]; j++) {
                            targetGrid[i - 1][j - 1] = -1;
                        }
                    }
                }
            }
            if (!found) break;
        }
        return true;        
    }
}