#https://leetcode.com/problems/n-queens/
#The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
#Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
#Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
# 
#Example 1:
#Input: n = 4
#Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
#Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
#Example 2:
#Input: n = 1
#Output: [["Q"]]
# 
#Constraints:
#	1 <= n <= 9
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        def solveNQueens(n):
            def is_not_under_attack(row, col):
                for prev_row in range(row):
                    if board[prev_row] == col or \
                            board[prev_row] - prev_row == col - row or \
                            board[prev_row] + prev_row == col + row:
                        return False
                return True

            def place_queen(row, col):
                board[row] = col

            def remove_queen(row, col):
                board[row] = -1

            def add_solution():
                solution = []
                for i in range(n):
                    solution.append('.' * board[i] + 'Q' + '.' * (n - board[i] - 1))
                result.append(solution)

            def backtrack(row):
                for col in range(n):
                    if is_not_under_attack(row, col):
                        place_queen(row, col)
                        if row + 1 == n:
                            add_solution()
                        else:
                            backtrack(row + 1)
                        remove_queen(row, col)

            result = []
            board = [-1] * n
            backtrack(0)
            return result

        return solveNQueens(n)        