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
    *returnSize = 0;
    int m = boardSize, n = boardColSize[0];
    int** trie = (int**)malloc(26 * sizeof(int*));
    for (int i = 0; i < 26; i++) {
        trie[i] = NULL;
    }
    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]);
        int** node = trie;
        for (int j = 0; j < len; j++) {
            int index = words[i][j] - 'a';
            if (node[index] == NULL) {
                node[index] = (int*)malloc(27 * sizeof(int));
                for (int k = 0; k < 26; k++) {
                    node[index][k] = 0;
                }
                node[index][26] = 0;
            }
            node = (int**)node[index];
        }
        node[26] = 1;
    }
    int* visited = (int*)malloc(m * n * sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i * n + j] = 0;
        }
    }
    char* word = (char*)malloc(11 * sizeof(char));
    word[0] = '\0';
    char** result = (char**)malloc(10000 * sizeof(char*));
    dfs(board, m, n, trie, visited, 0, 0, word, result, returnSize);
    free(word);
    for (int i = 0; i < 26; i++) {
        if (trie[i] != NULL) {
            free(trie[i]);
        }
    }
    free(trie);
    free(visited);
    return result;    
}