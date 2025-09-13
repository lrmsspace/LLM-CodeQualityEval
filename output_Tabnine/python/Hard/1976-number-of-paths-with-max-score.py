#https://leetcode.com/problems/number-of-paths-with-max-score/
#You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.
#You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.
#Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.
#In case there is no path, return [0, 0].
# 
#Example 1:
#Input: board = ["E23","2X2","12S"]
#Output: [7,1]
#Example 2:
#Input: board = ["E12","1X1","21S"]
#Output: [4,2]
#Example 3:
#Input: board = ["E11","XXX","11S"]
#Output: [0,0]
# 
#Constraints:
#	2 <= board.length == board[i].length <= 100
class Solution(object):
    def pathsWithMaxScore(self, board):
        """
        :type board: List[str]
        :rtype: List[int]
        """
        MOD = 10**9 + 7
        rows, cols = len(board), len(board[0])
        dp = [[0]*cols for _ in range(rows)]
        dp[-1][-1] = 1
        
        for i in range(rows-2, -1, -1):
            for j in range(cols-2, -1, -1):
                if board[i+1][j+1] == 'X':
                    dp[i][j] = 0
                else:
                    dp[i][j] = (dp[i+1][j] + dp[i][j+1] + dp[i+1][j+1]) % MOD
        
        if board[0][0] == 'X':
            return [0, 0]
        else:
            return [dp[0][0], 1]
        
        