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
        int[][] dx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int[][] color = new int[m][n];
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (color[i][j] == 0) {
                    int c = targetGrid[i][j], x1 = m, y1 = n, x2 = -1, y2 = -1;
                    Queue<int[]> q = new LinkedList<>();
                    q.offer(new int[]{i, j});
                    color[i][j] = c;
                    
                    while (!q.isEmpty()) {
                        int[] p = q.poll();
                        x1 = Math.min(x1, p[0]);
                        y1 = Math.min(y1, p[1]);
                        x2 = Math.max(x2, p[0]);
                        y2 = Math.max(y2, p[1]);
                        
                        for (int[] d : dx) {
                            int nx = p[0] + d[0], ny = p[1] + d[1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && targetGrid[nx][ny] == c && color[nx][ny] == 0) {
                                q.offer(new int[]{nx, ny});
                                color[nx][ny] = c;
                            }
                        }
                    }
                    
                    if (x1 > 0 && targetGrid[x1 - 1][y1] == c) {
                        return false;
                    }
                    if (x2 < m - 1 && targetGrid[x2 + 1][y1] == c) {
                        return false;
                    }
                    if (y1 > 0 && targetGrid[x1][y1 - 1] == c) {
                        return false;
                    }
                    if (y2 < n - 1 && targetGrid[x1][y2 + 1] == c) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
}