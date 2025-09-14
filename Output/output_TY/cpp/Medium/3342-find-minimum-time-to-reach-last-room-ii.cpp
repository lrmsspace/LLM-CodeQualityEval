/*
 There is a dungeon with n x m rooms arranged as a grid.
 You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.
 Return the minimum time to reach the room (n - 1, m - 1).
 Two rooms are adjacent if they share a common wall, either horizontally or vertically.
 Example 1:
 Input: moveTime = [[0,4],[4,4]]
 Output: 7
 Explanation:
 The minimum time required is 7 seconds.
 At time t == 4, move from room (0, 0) to room (1, 0) in one second.
 At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
 Example 2:
 Input: moveTime = [[0,0,0,0],[0,0,0,0]]
 Output: 6
 Explanation:
 The minimum time required is 6 seconds.
 At time t == 0, move from room (0, 0) to room (1, 0) in one second.
 At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
 At time t == 3, move from room (1, 1) to room (1, 2) in one second.
 At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.
 Example 3:
 Input: moveTime = [[0,1],[1,2]]
 Output: 4
 Constraints:
 2 <= n == moveTime.length <= 750
 2 <= m == moveTime[i].length <= 750
 0 <= moveTime[i][j] <= 109
*/

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = moveTime[0][0];
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + moveTime[i][0];
        }
        
        for (int j = 1; j < m; j++) {
            dp[0][j] = dp[0][j - 1] + moveTime[0][j];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + moveTime[i][j];
            }
            for (int j = 1; j < m; j++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + moveTime[i][j]);
            }
        }
        return dp[n - 1][m - 1];
        
    }
};