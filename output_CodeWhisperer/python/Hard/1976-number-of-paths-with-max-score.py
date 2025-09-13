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
        n = len(board)
        dp = [[[0, 0] for _ in range(n + 1)] for _ in range(n + 1)]
        dp[n - 1][n - 1] = [0, 1]
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if board[i][j] == 'X':
                    dp[i][j] = [0, 0]
                else:
                    max_sum = 0
                    count = 0
                    for dx, dy in [(0, -1), (-1, 0), (-1, -1)]:
                        nx, ny = i + dx, j + dy
                        if 0 <= nx < n and 0 <= ny < n:
                            if dp[nx][ny][0] > max_sum:
                                max_sum = dp[nx][ny][0]
                                count = dp[nx][ny][1]
                            elif dp[nx][ny][0] == max_sum:
                                count += dp[nx][ny][1]
                    if i == 0 and j == 0:
                        count = 0
                    if board[i][j] in '123456789':
                        max_sum += int(board[i][j])
                    dp[i][j] = [max_sum, count % (10 ** 9 + 7)]
        return dp[0][0]
        