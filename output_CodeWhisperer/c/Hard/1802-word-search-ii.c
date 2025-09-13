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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize) {
    // Initialize return values
    *returnSize = 0;
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    
    // Edge cases
    if (boardSize == 0 || boardColSize[0] == 0 || wordsSize == 0) {
        return result;
    }
    
    // Build Trie with all words
    TrieNode* root = createNode();
    for (int i = 0; i < wordsSize; i++) {
        insert(root, words[i]);
    }
    
    // Search for words on the board
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            dfs(board, boardSize, boardColSize, i, j, root, result, returnSize);
        }
    }
    
    // Free the Trie (in a real implementation, we would need a proper cleanup function)
    // For brevity, I'm omitting the Trie cleanup here
    
    return result;  

}