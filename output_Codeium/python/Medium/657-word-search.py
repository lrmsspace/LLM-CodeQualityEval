#https://leetcode.com/problems/word-search/
#Given an m x n grid of characters board and a string word, return true if word exists in the grid.
#The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
# 
#Example 1:
#Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
#Output: true
#Example 2:
#Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
#Output: true
#Example 3:
#Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
#Output: false
# 
#Constraints:
#	m == board.length
#	n = board[i].length
#	1 <= m, n <= 6
#	1 <= word.length <= 15
#	board and word consists of only lowercase and uppercase English letters.
# 
#Follow up: Could you use search pruning to make your solution faster with a larger board?
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        m, n = len(board), len(board[0])
        visited = set()
        
        def dfs(i, j, k):
            if k == len(word):
                return True
            if i < 0 or j < 0 or i >= m or j >= n or word[k] != board[i][j] or (i, j) in visited:
                return False
            visited.add((i, j))
            res = dfs(i+1, j, k+1) or dfs(i-1, j, k+1) or dfs(i, j+1, k+1) or dfs(i, j-1, k+1)
            visited.remove((i, j))
            return res
        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False
