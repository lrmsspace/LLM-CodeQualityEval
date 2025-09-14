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
        int n = board.size(), m = board[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<vector<int>> cnt(n, vector<int>(m, 0));
        cnt[n-1][m-1] = 1;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(board[i][j] == 'X') continue;
                if(i == n-1 && j == m-1){
                    dp[i][j] = 0;
                    cnt[i][j] = 1;
                    continue;
                }
                int mx = 0, c = 0;
                if(i < n-1){
                    if(board[i+1][j] != 'X'){
                        mx = max(mx, dp[i+1][j]);
                        c += cnt[i+1][j];
                    }
                }
                if(j < m-1){
                    if(board[i][j+1] != 'X'){
                        mx = max(mx, dp[i][j+1]);
                        c += cnt[i][j+1];
                    }
                }
                if(i < n-1 && j < m-1){
                    if(board[i+1][j+1] != 'X'){
                        mx = max(mx, dp[i+1][j+1]);
                        c += cnt[i+1][j+1];
                    }
                }
                if(c == 0){
                    dp[i][j] = 0;
                    cnt[i][j] = 0;
                }else{
                    dp[i][j] = mx + (board[i][j] == 'S' ? 0 : board[i][j] - '0');
                    cnt[i][j] = c % 1000000007;
                }
            }
        }
        if(cnt[0][0] == 0) return vector<int>{0, 0};
        else return vector<int>{dp[0][0], cnt[0][0]};      
    }
};