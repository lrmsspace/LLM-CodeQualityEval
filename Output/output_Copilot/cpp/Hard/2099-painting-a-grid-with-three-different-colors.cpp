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
public:
    int colorTheGrid(int m, int n) {
        const int MOD = 1e9 + 7;
        vector<int> masks;
        for (int mask = 0; mask < (1 << (2 * m)); ++mask) {
            bool ok = true;
            for (int i = 0; i < m; ++i) {
                if ((mask & (3 << (2 * i))) == (3 << (2 * i))) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                masks.push_back(mask);
            }
        }
        vector<vector<int>> dp(n, vector<int>(masks.size(), 0));
        for (int i = 0; i < masks.size(); ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < masks.size(); ++j) {
                for (int k = 0; k < masks.size(); ++k) {
                    if (check(masks[j], masks[k], m)) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < masks.size(); ++i) {
            ans = (ans + dp[n - 1][i]) % MOD;
        }
        return ans;        
    }
};