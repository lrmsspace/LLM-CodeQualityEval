/**https://leetcode.com/problems/largest-plus-sign/ */
//You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.
//Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.
//An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.
// 
//Example 1:
//Input: n = 5, mines = [[4,2]]
//Output: 2
//Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
//Example 2:
//Input: n = 1, mines = [[0,0]]
//Output: 0
//Explanation: There is no plus sign, so return 0.
// 
//Constraints:
//	1 <= n <= 500
//	1 <= mines.length <= 5000
//	0 <= xi, yi < n
//	All the pairs (xi, yi) are unique.
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (auto& mine : mines) {
            dp[mine[0]][mine[1]] = 0;
        }
        
        for (int i = 0; i < n; ++i) {
            int left = 0, right = n - 1;
            while (left <= right) {
                if (dp[i][left] == 0) ++left;
                else if (dp[i][right] == 0) --right;
                else {
                    dp[i][left] = min(dp[i][left], right - left + 1);
                    dp[i][right] = min(dp[i][right], right - left + 1);
                    ++left;
                    --right;
                }
            }
        }
        
        for (int j = 0; j < n; ++j) {
            int top = 0, bottom = n - 1;
            while (top <= bottom) {
                if (dp[top][j] == 0) ++top;
                else if (dp[bottom][j] == 0) --bottom;
                else {
                    dp[top][j] = min(dp[top][j], bottom - top + 1);
                    dp[bottom][j] = min(dp[bottom][j], bottom - top + 1);
                    ++top;
                    --bottom;
                }
            }
        }
        
        int maxOrder = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                maxOrder = max(maxOrder, dp[i][j]);
            }
        }
        return maxOrder;
        
    }
};