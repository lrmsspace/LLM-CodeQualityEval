/**https://leetcode.com/problems/knight-probability-in-chessboard/ */
//On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
//A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
//Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
//The knight continues moving until it has made exactly k moves or has moved off the chessboard.
//Return the probability that the knight remains on the board after it has stopped moving.
// 
//Example 1:
//Input: n = 3, k = 2, row = 0, column = 0
//Output: 0.06250
//Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
//From each of those positions, there are also two moves that will keep the knight on the board.
//The total probability the knight stays on the board is 0.0625.
//Example 2:
//Input: n = 1, k = 0, row = 0, column = 0
//Output: 1.00000
// 
//Constraints:
//	1 <= n <= 25
//	0 <= k <= 100
//	0 <= row, column <= n - 1
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k+1, 0)));
        dp[row][column][0] = 1;
        vector<vector<int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        for(int i=1; i<=k; i++){
            for(int j=0; j<n; j++){
                for(int l=0; l<n; l++){
                    for(auto move : moves){
                        int x = j + move[0];
                        int y = l + move[1];
                        if(x>=0 && x<n && y>=0 && y<n){
                            dp[x][y][i] += dp[j][l][i-1]/8;
                        }
                    }
                }
            }
        }
        double res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                res += dp[i][j][k];
            }
        }
        return res;     
    }
};