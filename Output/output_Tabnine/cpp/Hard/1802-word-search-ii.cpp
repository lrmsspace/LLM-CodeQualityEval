/**https://leetcode.com/problems/word-search-ii/ */
//Given an m x n board of characters and a list of strings words, return all words on the board.
//Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
// 
//Example 1:
//Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
//Output: ["eat","oath"]
//Example 2:
//Input: board = [["a","b"],["c","d"]], words = ["abcb"]
//Output: []
// 
//Constraints:
//	m == board.length
//	n == board[i].length
//	1 <= m, n <= 12
//	board[i][j] is a lowercase English letter.
//	1 <= words.length <= 3 * 104
//	1 <= words[i].length <= 10
//	words[i] consists of lowercase English letters.
//	All the strings of words are unique.
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || board[0].empty()) return res;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (const auto& word : words) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dfs(board, visited, i, j, word, 0)) res.push_back(word);
                }
            }
        }
        return res;
        
    }
};