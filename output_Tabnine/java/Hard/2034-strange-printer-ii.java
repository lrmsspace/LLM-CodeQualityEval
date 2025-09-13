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
        int[] colorCount = new int[61];
        int[] rowMin = new int[m];
        int[] colMin = new int[n];
        int[] rowMax = new int[m];
        int[] colMax = new int[n];
        
        for (int i = 0; i < m; i++) {
            rowMin[i] = n;
            rowMax[i] = -1;
        }
        for (int j = 0; j < n; j++) {
            colMin[j] = m;
            colMax[j] = -1;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int color = targetGrid[i][j];
                colorCount[color]++;
                rowMin[i] = Math.min(rowMin[i], j);
                rowMax[i] = Math.max(rowMax[i], j);
                colMin[j] = Math.min(colMin[j], i);
                colMax[j] = Math.max(colMax[j], i);
            }
        }
        
        Deque<int[]> queue = new ArrayDeque<>();
        for (int i = 1; i <= 60; i++) {
            if (colorCount[i] > 0) {
                queue.add(new int[]{i, rowMin[colorCount[i] - 1], rowMax[colorCount[i] - 1], colMin[colorCount[i] - 1], colMax[colorCount[i] - 1]});
            }
        }
        
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int color = cur[0];
            int minRow = cur[1];
            int maxRow = cur[2];
            int minCol = cur[3];
            int maxCol = cur[4];
            
            boolean valid = true;
            for (int i = minRow; i <= maxRow; i++) {
                for (int j = minCol; j <= maxCol; j++) {
                    if (targetGrid[i][j]!= color) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) {
                    break;
                }
            }
    
            if (valid) {
                continue;
            }
    
            for (int i = minRow; i <= maxRow; i++) {
                for (int j = minCol; j <= maxCol; j++) {
                    targetGrid[i][j] = 0;
                }
            }
            
            for (int i = minRow; i <= maxRow; i++) {
                int count = 0;
                for (int j = minCol; j <= maxCol; j++) {
                    if (targetGrid[i][j]!= 0) {
                        count++;
                    }
                }
                if (count > 0) {
                    queue.add(new int[]{color, rowMin[i], rowMax[i], minCol, maxCol});
                }
            }
    
            for (int j = minCol; j <= maxCol; j++) {
                int count = 0;
                for (int i = minRow; i <= maxRow; i++) {
                    if (targetGrid[i][j]!= 0) {
                        count++;
                    }
                }
                if (count > 0) {
                    queue.add(new int[]{color, rowMin[minRow], rowMax[maxRow], minCol, maxCol});
                }
            }
        }
            return false;
    }
}