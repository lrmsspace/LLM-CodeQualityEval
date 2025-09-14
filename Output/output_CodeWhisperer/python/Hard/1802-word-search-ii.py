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
        def dfs(i, j, word):
            if not word:
                return True
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] != word[0]:
                return False
            temp = board[i][j]
            board[i][j] = '#'
            res = dfs(i+1, j, word[1:]) or dfs(i-1, j, word[1:]) or dfs(i, j+1, word[1:]) or dfs(i, j-1, word[1:])
            board[i][j] = temp
            return res
        
        res = []
        for word in words:
            found = False
            for i in range(len(board)):
                for j in range(len(board[0])):
                    if dfs(i, j, word):
                        res.append(word)
                        found = True
                        break
                if found:
                    break
        return res
        