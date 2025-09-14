/**https://leetcode.com/problems/max-points-on-a-line/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
// 
//Example 1:
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 3
//Example 2:
//Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//Output: 4
// 
//Constraints:
//	1 <= points.length <= 300
//	points[i].length == 2
//	-104 <= xi, yi <= 104
//	All the points are unique.
class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        int m = points[0].length;
        long[][] dp = new long[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = points[i][j];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long max = 0;
                for (int k = 0; k < m; k++) {
                    if (j != k) {
                        max = Math.max(max, dp[i - 1][k] - Math.abs(j - k));
                    }
                }
            }
        }  
        long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = Math.max(ans, dp[n - 1][i]);
        }
        return ans; 
    }
}