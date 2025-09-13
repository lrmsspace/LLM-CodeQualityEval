/**https://leetcode.com/problems/number-of-paths-with-max-score/ */
//You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.
//You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.
//Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.
//In case there is no path, return [0, 0].
// 
//Example 1:
//Input: board = ["E23","2X2","12S"]
//Output: [7,1]
//Example 2:
//Input: board = ["E12","1X1","21S"]
//Output: [4,2]
//Example 3:
//Input: board = ["E11","XXX","11S"]
//Output: [0,0]
// 
//Constraints:
//	2 <= board.length == board[i].length <= 100
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)), cnt(n, vector<int>(n, 0));
        dp[n-1][n-1] = board[n-1][n-1] - '0';
        cnt[n-1][n-1] = 1;
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {-1, -1}};
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (board[i][j] == 'X') continue;
                for (const auto& d : dir) {
                    int ni = i + d.first, nj = j + d.second;
                    if (ni >= 0 && nj >= 0 && board[ni][nj] != 'X' && dp[ni][nj] > dp[i][j]) {
                        if (dp[ni][nj] == dp[i][j] + (board[i][j] - '0')) cnt[i][j] += cnt[ni][nj];
                        else cnt[i][j] = cnt[ni][nj];
                        dp[i][j] = dp[ni][nj] + (board[i][j] - '0');
                    }
                }
            }
        }
        return {dp[0][0], cnt[0][0]};
    }
};