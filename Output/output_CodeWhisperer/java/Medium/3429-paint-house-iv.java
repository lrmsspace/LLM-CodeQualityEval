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
        int k = cost[0].length;
        long[][] dp = new long[n][k];
        long min1 = 0, min2 = 0, min1Idx = -1;
        for(int i = 0; i < n; i++) {
            long curMin1 = Long.MAX_VALUE, curMin2 = Long.MAX_VALUE, curMin1Idx = -1;
            for(int j = 0; j < k; j++) {
                if(i == 0) {
                    dp[i][j] = cost[i][j];
                } else {
                    if(j == min1Idx) {
                        dp[i][j] = cost[i][j] + min2;
                    } else {
                        dp[i][j] = cost[i][j] + min1;
                    }
                }
                if(dp[i][j] <= curMin1) {
                    curMin2 = curMin1;
                    curMin1 = dp[i][j];
                    curMin1Idx = j;
                } else if(dp[i][j] < curMin2) {
                    curMin2 = dp[i][j];
                }
            }
            min1 = curMin1;
            min2 = curMin2;
            min1Idx = curMin1Idx;
        }
        long res = Long.MAX_VALUE;
        for(int i = 0; i < k; i++) {
            res = Math.min(res, dp[n-1][i]);
        }
        return res;        
    }
}