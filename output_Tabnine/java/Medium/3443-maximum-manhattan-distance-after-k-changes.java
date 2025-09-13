/*
 You are given a string s consisting of the characters 'N', 'S', 'E', and 'W', where s[i] indicates movements in an infinite grid:
 'N' : Move north by 1 unit.
 'S' : Move south by 1 unit.
 'E' : Move east by 1 unit.
 'W' : Move west by 1 unit.
 Initially, you are at the origin (0, 0). You can change at most k characters to any of the four directions.
 Find the maximum Manhattan distance from the origin that can be achieved at any time while performing the movements in order.
 The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
 Example 1:
 Input: s = "NWSE", k = 1
 Output: 3
 Explanation:
 Change s[2] from 'S' to 'N'. The string s becomes "NWNE".
 Movement
 Position (x, y)
 Manhattan Distance
 Maximum
 s[0] == 'N'
 (0, 1)
 0 + 1 = 1
 1
 s[1] == 'W'
 (-1, 1)
 1 + 1 = 2
 2
 s[2] == 'N'
 (-1, 2)
 1 + 2 = 3
 3
 s[3] == 'E'
 (0, 2)
 0 + 2 = 2
 3
 The maximum Manhattan distance from the origin that can be achieved is 3. Hence, 3 is the output.
 Example 2:
 Input: s = "NSWWEW", k = 3
 Output: 6
 Explanation:
 Change s[1] from 'S' to 'N', and s[4] from 'E' to 'W'. The string s becomes "NNWWWW".
 The maximum Manhattan distance from the origin that can be achieved is 6. Hence, 6 is the output.
 Constraints:
 1 <= s.length <= 105
 0 <= k <= s.length
 s consists of only 'N', 'S', 'E', and 'W'.
*/

class Solution {
    public int maxDistance(String s, int k) {


        int n = s.length();
        int[][] dp = new int[n + 1][k + 1];
        int[][] pos = new int[n + 1][k + 1];    
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }   
        dp[0][0] = 0;   
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {  
                if (s.charAt(i - 1) == 'N') {
                    pos[i][j] = 0;
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + 1);
                }
                if (s.charAt(i - 1) == 'S') {
                    pos[i][j] = 1;
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + 1);
                }
                if (s.charAt(i - 1) == 'E') {
                    pos[i][j] = 2;
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + 1);    
                    if (j > 0) {
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1] + 1);
                    }

                    if (j < k) {
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][j + 1] + 1);
                    }
                }

                if (s.charAt(i - 1) == 'W') {
                    pos[i][j] = 3;
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + 1);
                    if (j > 0) {
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1] + 1);
                    }

                    if (j < k) {
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][j + 1] + 1);
                    }
                }

                if (j > 0 && pos[i][j]!= pos[i][j - 1]) {
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                if (j < k && pos[i][j]!= pos[i][j + 1]) {
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j + 1] + 1);
                }

                if (i > 1 && pos[i][j]!= pos[i - 2][j]) {
                    dp[i][j] = Math.min(dp[i][j], dp[i - 2][j] + 1);
                }
            }   

            for (int j = 1; j <= k; j++) {
                dp[0][j] = Integer.MAX_VALUE;
            }
            dp[0][0] = 0;
            
            for (int j = 1; j <= k; j++) {
                dp[0][j] = dp[0][j - 1] + 1;
            }   
            for (int i = 1; i <= n; i++) {
                dp[i][0] = dp[i - 1][0] + 1;
            }   

            dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + 1);
        }   
        return dp[n][k];
        
    }
}