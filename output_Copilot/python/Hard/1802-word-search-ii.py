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
        # 1. 创建字典树
        trie = {}
        for word in words:
            node = trie
            for char in word:
                if char not in node:
                    node[char] = {}
                node = node[char]
            node['#'] = True        
        # 2. 定义方向数组
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        # 3. 定义回溯函数
        def backtrack(x, y, node, path):
            if '#' in node:
                result.add(path)
                del node['#']
            if not (0 <= x < len(board) and 0 <= y < len(board[0])):
                return
            temp = board[x][y]
            if temp not in node:
                return
            board[x][y] = '#'
            for dx, dy in directions:
                backtrack(x + dx, y + dy, node[temp], path + temp)
            board[x][y] = temp
        # 4. 初始化结果集
        result = set()
        # 5. 遍历棋盘
        for i in range(len(board)):
            for j in range(len(board[0])):
                backtrack(i, j, trie, '')   
        return list(result)
#         # 1. 创建字典树