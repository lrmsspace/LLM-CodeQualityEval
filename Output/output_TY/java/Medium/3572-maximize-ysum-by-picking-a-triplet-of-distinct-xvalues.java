/*
 You are given two integer arrays x and y, each of length n. You must choose three distinct indices i, j, and k such that:
 x[i] != x[j]
 x[j] != x[k]
 x[k] != x[i]
 Your goal is to maximize the value of y[i] + y[j] + y[k] under these conditions. Return the maximum possible sum that can be obtained by choosing such a triplet of indices.
 If no such triplet exists, return -1.
 Example 1:
 Input: x = [1,2,1,3,2], y = [5,3,4,6,2]
 Output: 14
 Explanation:
 Choose i = 0 (x[i] = 1, y[i] = 5), j = 1 (x[j] = 2, y[j] = 3), k = 3 (x[k] = 3, y[k] = 6).
 All three values chosen from x are distinct. 5 + 3 + 6 = 14 is the maximum we can obtain. Hence, the output is 14.
 Example 2:
 Input: x = [1,2,1,2], y = [4,5,6,7]
 Output: -1
 Explanation:
 There are only two distinct values in x. Hence, the output is -1.
 Constraints:
 n == x.length == y.length
 3 <= n <= 105
 1 <= x[i], y[i] <= 106
*/

class Solution {
    public int maxSumDistinctTriplet(int[] x, int[] y) {
        int n = x.length;
        int[][] dp = new int[n][3];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                dp[i][j] = -1;
            }
        }
        for(int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < 3; j++) {
                int max_sum = -1;
                for(int k = 0; k < i; k++) {
                    if(x[i] != x[k] && x[i] != y[k] && y[i] != x[k] && y[i] != y[k]) {
                        max_sum = Math.max(max_sum, dp[k][j - 1] + x[i] * y[i]);
                    }
                }
                dp[i][j] = max_sum;
            }
        }
        return dp[n - 1][2];
    }
}