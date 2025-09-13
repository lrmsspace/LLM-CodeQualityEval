/**https://leetcode.com/problems/n-queens/ */
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
// 
//Example 1:
//Input: n = 4
//Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
//Example 2:
//Input: n = 1
//Output: [["Q"]]
// 
//Constraints:
//	1 <= n <= 9 
class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> result;
            vector<string> board(n, string(n, '.'));
            
            // Sets to keep track of occupied columns and diagonals
            vector<bool> cols(n, false);
            vector<bool> diag1(2 * n - 1, false);  // Main diagonals (top-left to bottom-right)
            vector<bool> diag2(2 * n - 1, false);  // Anti-diagonals (top-right to bottom-left)
            
            backtrack(result, board, 0, n, cols, diag1, diag2);
            return result;
        }
        
    private:
        void backtrack(vector<vector<string>>& result, vector<string>& board, int row, int n, 
                      vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
            // If we've placed queens in all rows, we have a valid solution
            if (row == n) {
                result.push_back(board);
                return;
            }
            
            // Try placing a queen in each column of the current row
            for (int col = 0; col < n; col++) {
                // Calculate diagonal indices
                int d1 = row + col;            // Main diagonal index
                int d2 = row - col + n - 1;    // Anti-diagonal index
                
                // Check if the position is under attack
                if (cols[col] || diag1[d1] || diag2[d2]) {
                    continue;  // Skip this position
                }
                
                // Place the queen
                board[row][col] = 'Q';
                cols[col] = true;
                diag1[d1] = true;
                diag2[d2] = true;
                
                // Recursively place queens in the next row
                backtrack(result, board, row + 1, n, cols, diag1, diag2);
                
                // Backtrack: remove the queen
                board[row][col] = '.';
                cols[col] = false;
                diag1[d1] = false;
                diag2[d2] = false;
            }
        }
    };
    