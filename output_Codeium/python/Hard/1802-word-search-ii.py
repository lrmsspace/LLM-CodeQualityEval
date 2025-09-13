#https://leetcode.com/problems/word-search-ii/
#Given an m x n board of characters and a list of strings words, return all words on the board.
#Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
# 
#Example 1:
#Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
#Output: ["eat","oath"]
#Example 2:
#Input: board = [["a","b"],["c","d"]], words = ["abcb"]
#Output: []
# 
#Constraints:
#	m == board.length
#	n == board[i].length
#	1 <= m, n <= 12
#	board[i][j] is a lowercase English letter.
#	1 <= words.length <= 3 * 104
#	1 <= words[i].length <= 10
#	words[i] consists of lowercase English letters.
#	All the strings of words are unique.
class Solution(object):
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        res = []
        trie = {}
        for w in words:
            node = trie
            for ch in w:
                node = node.setdefault(ch, {})
            node['$'] = w
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.dfs(board, i, j, trie, res)
        return res
    
    def dfs(self, board, i, j, node, res):
        ch = board[i][j]
        if ch not in node:
            return
        word = node[ch]['$']
        if word:
            res.append(word)
            node[ch]['$'] = None
        board[i][j] = '#'
        for d in [(0,1), (0,-1), (1,0), (-1,0)]:
            x, y = i + d[0], j + d[1]
            if 0 <= x < len(board) and 0 <= y < len(board[0]):
                self.dfs(board, x, y, node[ch], res)
        board[i][j] = ch
