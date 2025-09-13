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
        int m = grid.length, n = grid[0].length;
        int[][][] dp = new int[m][n][1 << 3];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < (1 << 3); k++) {
                    dp[i][j][k] = Integer.MAX_VALUE;
                }
            }
        }
        
        // Iterate through all possible rectangles
        for (int r1 = 0; r1 < m; r1++) {
            for (int c1 = 0; c1 < n; c1++) {
                for (int r2 = r1; r2 < m; r2++) {
                    for (int c2 = c1; c2 < n; c2++) {
                        int area = (r2 - r1 + 1) * (c2 - c1 + 1);
                        int mask = 0;
                        for (int i = r1; i <= r2; i++) {
                            for (int j = c1; j <= c2; j++) {
                                if (grid[i][j] == 1) {
                                    mask |= (1 << (i * n + j));
                                }
                            }
                        }
                        if (mask != 0) {
                            for (int k = 0; k < (1 << 3); k++) {
                                if ((k & mask) == 0) {
                                    dp[r2][c2][k | mask] = Math.min(dp[r2][c2][k | mask], dp[r1 - 1][c2][k] + area);
                                }
                            }
                        }
                    }
                }
            }
        }

        // Find the minimum sum of areas covering all ones
        int minSum = Integer.MAX_VALUE;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                minSum = Math.min(minSum, dp[i][j][(1 << (m * n)) - 1]);
            }
        }

        return minSum;  
            
    }
}