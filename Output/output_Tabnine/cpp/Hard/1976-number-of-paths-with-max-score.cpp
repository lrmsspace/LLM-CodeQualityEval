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
        int m = board.size();
        int n = board[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(10, 0)));
        dp[m - 1][n - 1][board[m - 1][n - 1] - '0'] = 1;
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'X') continue;
                for (int k = 9; k >= 0; --k) {
                    if (dp[i + 1][j][k] > 0) {
                        for (int l = 0; l <= 9; ++l) {
                            dp[i][j][(k + l) % 10] = (dp[i][j][(k + l) % 10] + dp[i + 1][j][k]) % (int(1e9) + 7);
                        }
                    }
                }
            }
        }
        int maxSum = 0;
        int maxCount = 0;
        for (int i = 0; i < 10; ++i) {
            if (dp[0][0][i] > maxSum) {
                maxSum = dp[0][0][i];
                maxCount = dp[0][0][i];
            } else if (dp[0][0][i] == maxSum) {
                maxCount = (maxCount + dp[0][0][i]) % (int(1e9) + 7);
            }
        }
        return {maxSum, maxCount};       
    }
};