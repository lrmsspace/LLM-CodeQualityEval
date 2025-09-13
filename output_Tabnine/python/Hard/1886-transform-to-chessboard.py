#https://leetcode.com/problems/transform-to-chessboard/
#You are given an n x n binary grid board. In each move, you can swap any two rows with each other, or any two columns with each other.
#Return the minimum number of moves to transform the board into a chessboard board. If the task is impossible, return -1.
#A chessboard board is a board where no 0's and no 1's are 4-directionally adjacent.
# 
#Example 1:
#Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
#Output: 2
#Explanation: One potential sequence of moves is shown.
#The first move swaps the first and second column.
#The second move swaps the second and third row.
#Example 2:
#Input: board = [[0,1],[1,0]]
#Output: 0
#Explanation: Also note that the board with 0 in the top left corner, is also a valid chessboard.
#Example 3:
#Input: board = [[1,0],[1,0]]
#Output: -1
#Explanation: No matter what sequence of moves you make, you cannot end with a valid chessboard.
# 
#Constraints:
#	n == board.length
#	n == board[i].length
#	2 <= n <= 30
#	board[i][j] is either 0 or 1.
class Solution(object):
    def movesToChessboard(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        def count_ones(board, row, col):
            count = 0
            for i in range(n):
                for j in range(n):
                    if board[i][j] == 1:
                        count += abs(i - row) + abs(j - col)
            return count
        
        n = len(board)
        # Step 1: Check if the board is already a valid chessboard
        for i in range(n):
            if board[i][0]!= i % 2:
                return -1
        
        # Step 2: Calculate the sum of moves for each row and column
        row_sum, col_sum = 0, 0
        for i in range(n):
            row_sum += count_ones(board, i, 0)
            col_sum += count_ones(board, 0, i)
        
        # Step 3: Calculate the minimum moves by finding the difference between row_sum and col_sum
        min_moves = min(row_sum, col_sum)
        
        # Step 4: Calculate the maximum moves by finding the sum of row_sum and col_sum
        max_moves = max(row_sum, col_sum)
        
        # Step 5: Return the minimum number of moves
        return min_moves
        