/**https://leetcode.com/problems/word-search/ */
//Given an m x n grid of characters board and a string word, return true if word exists in the grid.
//The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
// 
//Example 1:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
//Output: true
//Example 2:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
//Output: true
//Example 3:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
//Output: false
// 
//Constraints:
//	m == board.length
//	n = board[i].length
//	1 <= m, n <= 6
//	1 <= word.length <= 15
//	board and word consists of only lowercase and uppercase English letters.
// 
//Follow up: Could you use search pruning to make your solution faster with a larger board? 
class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) {
            int m = board.size();
            int n = board[0].size();
            
            // Try starting the search from each cell in the board
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == word[0]) {
                        if (dfs(board, word, i, j, 0)) {
                            return true;
                        }
                    }
                }
            }
            
            return false;
        }
        
    private:
        // Directions: up, right, down, left
        const vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int index) {
            // If we've matched all characters in the word, we found it
            if (index == word.length()) {
                return true;
            }
            
            int m = board.size();
            int n = board[0].size();
            
            // Check if current position is valid and matches the current character
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
                return false;
            }
            
            // Mark the current cell as visited by changing its value temporarily
            char temp = board[i][j];
            board[i][j] = '#';
            
            // Try all four directions
            for (const auto& [di, dj] : dirs) {
                int ni = i + di;
                int nj = j + dj;
                
                if (dfs(board, word, ni, nj, index + 1)) {
                    // Restore the board before returning
                    board[i][j] = temp;
                    return true;
                }
            }
            
            // Restore the board for backtracking
            board[i][j] = temp;
            
            return false;
        }
    };
    