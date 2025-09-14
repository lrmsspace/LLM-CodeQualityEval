/**https://leetcode.com/problems/largest-1-bordered-square/ */
//Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.
// 
//Example 1:
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
//Output: 9
//Example 2:
//Input: grid = [[1,1,0,0]]
//Output: 1
// 
//Constraints:
//	1 <= grid.length <= 100
//	1 <= grid[0].length <= 100
//	grid[i][j] is 0 or 1
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxSide = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = min(min(i, j), min(n - i - 1, m - j - 1)) + 1;
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        
        int ans = 0;
        for (int side = maxSide; side >= 1; side--) {
            for (int i = 0; i <= n - side; i++) {
                for (int j = 0; j <= m - side; j++) {
                    if (dp[i][j] == side &&
                        dp[i][j + side - 1] == side &&
                        dp[i + side - 1][j] == side &&
                        dp[i + side - 1][j + side - 1] == side) {
                        ans += side * side;
                        break;
                    }
                }
            }
        }
        
        return ans;
        
    }
};