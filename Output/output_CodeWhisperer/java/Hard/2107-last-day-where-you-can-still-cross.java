/**https://leetcode.com/problems/last-day-where-you-can-still-cross/ */
//There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.
//Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).
//You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).
//Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.
// 
//Example 1:
//Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
//Output: 2
//Explanation: The above image depicts how the matrix changes each day starting from day 0.
//The last day where it is possible to cross from top to bottom is on day 2.
//Example 2:
//Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
//Output: 1
//Explanation: The above image depicts how the matrix changes each day starting from day 0.
//The last day where it is possible to cross from top to bottom is on day 1.
//Example 3:
//Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
//Output: 3
//Explanation: The above image depicts how the matrix changes each day starting from day 0.
//The last day where it is possible to cross from top to bottom is on day 3.
// 
//Constraints:
//	2 <= row, col <= 2 * 104
//	4 <= row * col <= 2 * 104
//	cells.length == row * col
//	1 <= ri <= row
//	1 <= ci <= col
//	All the values of cells are unique.
import java.util.Arrays;
class Solution {
    public int latestDayToCross(int row, int col, int[][] cells) {
        int[][] grid = new int[row][col];
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (int i = 0; i < cells.length; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
            for (int[] d : directions) {
                int newR = r + d[0];
                int newC = c + d[1];
                if (newR >= 0 && newR < row && newC >= 0 && newC < col && grid[newR][newC] == 1) {
                    grid[r][c] = 0;
                    break;
                }
            }
            if (i == cells.length - 1) {
                return i;
            }
      }
      int left = 0;
      int right = cells.length - 1;
      
      while (left < right) {
          int mid = right - (right - left) / 2;
          for (int i = 0; i < row; i++) {
              Arrays.fill(grid[i], 0);
          }
          for (int i = 0; i <= mid; i++) {
              int r = cells[i][0] - 1;
              int c = cells[i][1] - 1;
              grid[r][c] = 1;
          }
          boolean[][] visited = new boolean[row][col];
          for (int c = 0; c < col; c++) {
              if (grid[0][c] == 0 && !visited[0][c]) {
                  if (dfs(grid, visited, directions, 0, c)) {
                      left = mid + 1;
                      break;
                  }
              }
          }
          if (left != mid + 1) {
              right = mid;
          }
      }
      return left;
    }
}