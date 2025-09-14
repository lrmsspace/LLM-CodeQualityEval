#https://leetcode.com/problems/maximum-students-taking-exam/
#Given a m * n matrix seats  that represent seats distributions in a classroom. If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character.
#Students can see the answers of those sitting next to the left, right, upper left and upper right, but he cannot see the answers of the student sitting directly in front or behind him. Return the maximum number of students that can take the exam together without any cheating being possible.
#Students must be placed in seats in good condition.
# 
#Example 1:
#Input: seats = [["#",".","#","#",".","#"],
#                [".","#","#","#","#","."],
#                ["#",".","#","#",".","#"]]
#Output: 4
#Explanation: Teacher can place 4 students in available seats so they don't cheat on the exam. 
#Example 2:
#Input: seats = [[".","#"],
#                ["#","#"],
#                ["#","."],
#                ["#","#"],
#                [".","#"]]
#Output: 3
#Explanation: Place all students in available seats. 
#Example 3:
#Input: seats = [["#",".",".",".","#"],
#                [".","#",".","#","."],
#                [".",".","#",".","."],
#                [".","#",".","#","."],
#                ["#",".",".",".","#"]]
#Output: 10
#Explanation: Place students in available seats in column 1, 3 and 5.
# 
#Constraints:
#	seats contains only characters '.' and'#'.
#	m == seats.length
#	n == seats[i].length
#	1 <= m <= 8
#	1 <= n <= 8
class Solution(object):
    def maxStudents(self, seats):
        """
        :type seats: List[List[str]]
        :rtype: int
        """
        m, n = len(seats), len(seats[0])
        valid = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if seats[i][j] == '.':
                    valid[i][j] = 1
        dp = [[0 for _ in range(1 << n)] for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1 << n):
                if (j & (j >> 1) == 0) and (j & valid[i - 1] == j):
                    for k in range(1 << n):
                        if (k & (j >> 1) == 0) and (k & (j << 1) == 0) and (k & valid[i - 2] == k):
                            dp[i][j] = max(dp[i][j], dp[i - 1][k] + bin(j).count('1'))
        return max(dp[m])
        