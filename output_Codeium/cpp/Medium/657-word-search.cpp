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
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        function<bool(int, int, int)> dfs = [&](int i, int j, int k) {
            if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[k])
                return false;
            if (k == word.size() - 1)
                return true;
            visited[i][j] = true;
            if (dfs(i - 1, j, k + 1) || dfs(i + 1, j, k + 1) || dfs(i, j - 1, k + 1) || dfs(i, j + 1, k + 1))
                return true;
            visited[i][j] = false;
            return false;
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (dfs(i, j, 0))
                    return true;
        return false;
    }
};