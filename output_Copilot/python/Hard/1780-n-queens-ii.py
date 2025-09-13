#https://leetcode.com/problems/n-queens-ii/
#The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
#Given an integer n, return the number of distinct solutions to the n-queens puzzle.
# 
#Example 1:
#Input: n = 4
#Output: 2
#Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
#Example 2:
#Input: n = 1
#Output: 1
# 
#Constraints:
#	1 <= n <= 9
class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        def backtrack(row, cols, diags1, diags2):
            if row == n:
                return 1
            count = 0
            for col in range(n):
                diag1 = row - col + n - 1
                diag2 = row + col
                if col in cols or diag1 in diags1 or diag2 in diags2:
                    continue
                cols.add(col)
                diags1.add(diag1)
                diags2.add(diag2)
                count += backtrack(row + 1, cols, diags1, diags2)
                cols.remove(col)
                diags1.remove(diag1)
                diags2.remove(diag2)
            return count

        return backtrack(0, set(), set(), set())        