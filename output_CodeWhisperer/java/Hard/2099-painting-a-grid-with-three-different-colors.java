/**https://leetcode.com/problems/painting-a-grid-with-three-different-colors/ */
//You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
//Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: m = 1, n = 1
//Output: 3
//Explanation: The three possible colorings are shown in the image above.
//Example 2:
//Input: m = 1, n = 2
//Output: 6
//Explanation: The six possible colorings are shown in the image above.
//Example 3:
//Input: m = 5, n = 5
//Output: 580986
// 
//Constraints:
//	1 <= m <= 5
//	1 <= n <= 1000
class Solution {
    public int colorTheGrid(int m, int n) {
        int mod = 1000000007;
        int[][] dp = new int[1000][1024];
        int[] color = new int[1000];
        for(int i = 0; i < 1000; i++){
            int x = i;
            for(int j = 0; j < 3; j++){
                color[i] = (color[i] << 3) + (x % 3);
                x /= 3;
            }
        }
        for(int i = 0; i < 1000; i++){
            for(int j = 0; j < 1024; j++){
                if((color[i] & j) == 0){
                    dp[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < 1000; j++){
                for(int k = 0; k < 1024; k++){
                    if(dp[j][k] > 0){
                        for(int l = 0; l < 1000; l++){
                            if((color[j] & color[l]) == 0){
                                dp[l][color[j]] = (dp[l][color[j]] + dp[j][k]) % mod;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 1000; i++){
            ans = (ans + dp[i][0]) % mod;
        }
        return ans;     
    }
}