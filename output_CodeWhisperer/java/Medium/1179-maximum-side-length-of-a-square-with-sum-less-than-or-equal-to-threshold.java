/**https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/ */
//Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.
// 
//Example 1:
//Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
//Output: 2
//Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
//Example 2:
//Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
//Output: 0
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 300
//	0 <= mat[i][j] <= 104
//	0 <= threshold <= 105
class Solution {
    public int maxSideLength(int[][] mat, int threshold) {
        int[][] dp = new int[mat.length + 1][mat[0].length + 1];
        int max = 0;
        for (int i = 1; i <= mat.length; i++) {
            for (int j = 1; j <= mat[0].length; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
                if (i - max >= 0 && j - max >= 0 && dp[i][j] - dp[i - max][j] - dp[i][j - max] + dp[i - max][j - max] <= threshold) {
                    max++;
                }
            }
        }
        return max;      
    }
}