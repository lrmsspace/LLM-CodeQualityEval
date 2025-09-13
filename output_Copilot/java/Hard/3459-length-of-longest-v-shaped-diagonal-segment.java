/*
 You are given a 2D integer matrix grid of size n x m, where each element is either 0, 1, or 2.
 A V-shaped diagonal segment is defined as:
 The segment starts with 1.
 The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
 The segment:
 Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
 Continues the sequence in the same diagonal direction.
 Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.
 Return the length of the longest V-shaped diagonal segment. If no valid segment exists, return 0.
 Example 1:
 Input: grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
 Output: 5
 Explanation:
 The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,2) → (1,3) → (2,4), takes a 90-degree clockwise turn at (2,4), and continues as (3,3) → (4,2).
 Example 2:
 Input: grid = [[2,2,2,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
 Output: 4
 Explanation:
 The longest V-shaped diagonal segment has a length of 4 and follows these coordinates: (2,3) → (3,2), takes a 90-degree clockwise turn at (3,2), and continues as (2,1) → (1,0).
 Example 3:
 Input: grid = [[1,2,2,2,2],[2,2,2,2,0],[2,0,0,0,0],[0,0,2,2,2],[2,0,0,2,0]]
 Output: 5
 Explanation:
 The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,0) → (1,1) → (2,2) → (3,3) → (4,4).
 Example 4:
 Input: grid = [[1]]
 Output: 1
 Explanation:
 The longest V-shaped diagonal segment has a length of 1 and follows these coordinates: (0,0).
 Constraints:
 n == grid.length
 m == grid[i].length
 1 <= n, m <= 500
 grid[i][j] is either 0, 1 or 2.
*/

class Solution {
    public int lenOfVDiagonal(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][][] dp = new int[n][m][2]; // dp[i][j][0] for no turn, dp[i][j][1] for one turn
        int maxLen = 0;

        // Initialize the dp array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j][0] = dp[i][j][1] = 0;
            }
        }   
        // Traverse the grid to find V-shaped diagonal segments
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j][0] = 1; // Start a new segment
                    maxLen = Math.max(maxLen, dp[i][j][0]);
                } else if (grid[i][j] == 2) {
                    // Continue the segment without turn
                    if (i > 0 && j > 0 && grid[i - 1][j - 1] == 1) {
                        dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
                        maxLen = Math.max(maxLen, dp[i][j][0]);
                    }
                    // Continue the segment with one turn
                    if (i > 0 && j < m - 1 && grid[i - 1][j + 1] == 1) {
                        dp[i][j][1] = dp[i - 1][j + 1][0] + 1;
                        maxLen = Math.max(maxLen, dp[i][j][1]);
                    }
                }
            }
        }
        // Check for segments that can turn 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    // Check for a turn from the left diagonal
                    if (i > 0 && j > 0 && dp[i - 1][j - 1][0] > 0) {
                        dp[i][j][1] = Math.max(dp[i][j][1], dp[i - 1][j - 1][0] + 1);
                        maxLen = Math.max(maxLen, dp[i][j][1]);
                    }
                    // Check for a turn from the right diagonal
                    if (i > 0 && j < m - 1 && dp[i - 1][j + 1][0] > 0) {
                        dp[i][j][1] = Math.max(dp[i][j][1], dp[i - 1][j + 1][0] + 1);
                        maxLen = Math.max(maxLen, dp[i][j][1]);
                    }
                }
            }
        }
        // Return the maximum length of the V-shaped diagonal segment found
        return maxLen > 0 ? maxLen : 0; // If no valid segment exists, return 0
    }
}