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
        res = []
        def backtrack(row, cols, pie, na):
            if row == n:
                res.append(["".join(["Q" if i in cols else "." for i in range(n)]) for cols in cols])
                return
            available = (1 << n) - 1 - (cols | pie | na)
            while available:
                p = available & (-available)
                available -= p
                backtrack(row + 1, cols | p, (pie | p) << 1, (na | p) >> 1)
        backtrack(0, 0, 0, 0)
        return res