/*
 You are given an even integer n representing the number of houses arranged in a straight line, and a 2D array cost of size n x 3, where cost[i][j] represents the cost of painting house i with color j + 1.
 The houses will look beautiful if they satisfy the following conditions:
 No two adjacent houses are painted the same color.
 Houses equidistant from the ends of the row are not painted the same color. For example, if n = 6, houses at positions (0, 5), (1, 4), and (2, 3) are considered equidistant.
 Return the minimum cost to paint the houses such that they look beautiful.
 Example 1:
 Input: n = 4, cost = [[3,5,7],[6,2,9],[4,8,1],[7,3,5]]
 Output: 9
 Explanation:
 The optimal painting sequence is [1, 2, 3, 2] with corresponding costs [3, 2, 1, 3]. This satisfies the following conditions:
 No adjacent houses have the same color.
 Houses at positions 0 and 3 (equidistant from the ends) are not painted the same color (1 != 2).
 Houses at positions 1 and 2 (equidistant from the ends) are not painted the same color (2 != 3).
 The minimum cost to paint the houses so that they look beautiful is 3 + 2 + 1 + 3 = 9.
 Example 2:
 Input: n = 6, cost = [[2,4,6],[5,3,8],[7,1,9],[4,6,2],[3,5,7],[8,2,4]]
 Output: 18
 Explanation:
 The optimal painting sequence is [1, 3, 2, 3, 1, 2] with corresponding costs [2, 8, 1, 2, 3, 2]. This satisfies the following conditions:
 No adjacent houses have the same color.
 Houses at positions 0 and 5 (equidistant from the ends) are not painted the same color (1 != 2).
 Houses at positions 1 and 4 (equidistant from the ends) are not painted the same color (3 != 1).
 Houses at positions 2 and 3 (equidistant from the ends) are not painted the same color (2 != 3).
 The minimum cost to paint the houses so that they look beautiful is 2 + 8 + 1 + 2 + 3 + 2 = 18.
 Constraints:
 2 <= n <= 105
 n is even.
 cost.length == n
 cost[i].length == 3
 0 <= cost[i][j] <= 105
*/

class Solution {
    public long minCost(int n, int[][] cost) {
        // Initialize a 3D dp array with dimensions n x 3 x 2 (to account for the two possible painting sequences)
        long[][][] dp = new long[n][3][2];
        
        // Initialize the first house in each color
        for (int color = 0; color < 3; color++) {
            dp[0][color][0] = cost[0][color];
            dp[0][color][1] = Long.MAX_VALUE;
        }
        // Initialize the first house in the second sequence
        dp[0][0][1] = dp[0][1][0] = Long.MAX_VALUE;
        // Initialize the first house in the third sequence
        dp[0][2][1] = dp[0][2][0] = Long.MAX_VALUE;
        // Initialize the remaining houses in the first sequence
        for (int i = 1; i < n; i++) {
            for (int color = 0; color < 3; color++) {
                dp[i][color][0] = Math.min(dp[i-1][(color+1)%3][0] + cost[i][color], dp[i-1][(color+2)%3][0] + cost[i][color]);
                dp[i][color][1] = Math.min(dp[i-1][(color+1)%3][1], dp[i-1][(color+2)%3][1]);
            }
        }
        // Initialize the remaining houses in the second sequence
        for (int i = 1; i < n; i++) {
            for (int color = 0; color < 3; color++) {
                dp[i][color][0] = Math.min(dp[i][color][0], dp[i-1][(color+1)%3][0] + cost[i][color]);
                dp[i][color][1] = Math.min(dp[i][color][1], dp[i-1][(color+1)%3][1] + cost[i][color]);
            }
        }
        // Initialize the remaining houses in the third sequence
        for (int i = 1; i < n; i++) {
            for (int color = 0; color < 3; color++) {
                dp[i][color][0] = Math.min(dp[i][color][0], dp[i-1][(color+1)%3][0] + cost[i][color]);
                dp[i][color][1] = Math.min(dp[i][color][1], dp[i-1][(color+1)%3][1] + cost[i][color]);
            }
        }
        // Return the minimum cost for the last house in each sequence
        return Math.min(Math.min(dp[n-1][0][0], dp[n-1][1][0]), dp[n-1][2][0]);
        
        
    }
}