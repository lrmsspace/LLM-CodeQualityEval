/*
 You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.
 Return the minimum possible sum of the area of these rectangles.
 Note that the rectangles are allowed to touch.
 Example 1:
 Input: grid = [[1,0,1],[1,1,1]]
 Output: 5
 Explanation:
 The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
 The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
 The 1 at (1, 1) is covered by a rectangle of area 1.
 Example 2:
 Input: grid = [[1,0,1,0],[0,1,0,1]]
 Output: 5
 Explanation:
 The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
 The 1 at (1, 1) is covered by a rectangle of area 1.
 The 1 at (1, 3) is covered by a rectangle of area 1.
 Constraints:
 1 <= grid.length, grid[i].length <= 30
 grid[i][j] is either 0 or 1.
 The input is generated such that there are at least three 1's in grid.
*/

class Solution {
    public int minimumSum(int[][] grid) {

        int rows = grid.length;
        int cols = grid[0].length;
        
        int[][] dp = new int[rows][cols];
        int[][] prefixSum = new int[rows + 1][cols + 1];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefixSum[i + 1][j + 1] = prefixSum[i + 1][j] + prefixSum[i][j + 1] - prefixSum[i][j] + grid[i][j];
                dp[i][j] = Math.min(dp[i][j], prefixSum[i + 1][j + 1] - prefixSum[i + 1][j] - prefixSum[i][j + 1] + prefixSum[i][j]);
            }
        }   

        int minSum = Integer.MAX_VALUE;
        for (int i = 0; i < rows - 2; i++) {
            for (int j = 0; j < cols - 2; j++) {
                for (int k = i + 1; k < rows; k++) {
                    for (int l = j + 1; l < cols; l++) {
                        minSum = Math.min(minSum, dp[i][j] + dp[k][l] + prefixSum[k + 1][l + 1] - prefixSum[i][l + 1] - prefixSum[k + 1][j] + prefixSum[i][j]);
                    }
                }
            }
        }
        
        return minSum;
        
    }
}