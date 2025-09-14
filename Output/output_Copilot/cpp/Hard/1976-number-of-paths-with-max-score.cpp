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
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> count(n, vector<int>(n, 0));
    const int MOD = 1e9 + 7;

    dp[n - 1][n - 1] = 0;
    count[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
        if (board[i][j] == 'X') continue;

        if (i < n - 1) {
            if (dp[i + 1][j] > dp[i][j]) {
            dp[i][j] = dp[i + 1][j];
            count[i][j] = count[i + 1][j];
            } else if (dp[i + 1][j] == dp[i][j]) {
            count[i][j] = (count[i][j] + count[i + 1][j]) % MOD;
            }
        }

        if (j < n - 1) {
            if (dp[i][j + 1] > dp[i][j]) {
            dp[i][j] = dp[i][j + 1];
            count[i][j] = count[i][j + 1];
            } else if (dp[i][j + 1] == dp[i][j]) {
            count[i][j] = (count[i][j] + count[i][j + 1]) % MOD;
            }
        }

        if (i < n - 1 && j < n - 1) {
            if (dp[i + 1][j + 1] > dp[i][j]) {
            dp[i][j] = dp[i + 1][j + 1];
            count[i][j] = count[i + 1][j + 1];
            } else if (dp[i + 1][j + 1] == dp[i][j]) {
            count[i][j] = (count[i][j] + count[i + 1][j + 1]) % MOD;
            }
        }

        if (board[i][j] >= '0' && board[i][j] <= '9') {
            dp[i][j] += board[i][j] - '0';
        }
        }
    }

    if (count[0][0] == 0) return {0, 0};
    return {dp[0][0], count[0][0]}; 
        }
};