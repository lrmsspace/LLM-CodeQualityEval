# There is a dungeon with n x m rooms arranged as a grid.
# You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds after which the room opens and can be moved to. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.
# Return the minimum time to reach the room (n - 1, m - 1).
# Two rooms are adjacent if they share a common wall, either horizontally or vertically.
# Example 1:
# Input: moveTime = [[0,4],[4,4]]
# Output: 6
# Explanation:
# The minimum time required is 6 seconds.
# At time t == 4, move from room (0, 0) to room (1, 0) in one second.
# At time t == 5, move from room (1, 0) to room (1, 1) in one second.
# Example 2:
# Input: moveTime = [[0,0,0],[0,0,0]]
# Output: 3
# Explanation:
# The minimum time required is 3 seconds.
# At time t == 0, move from room (0, 0) to room (1, 0) in one second.
# At time t == 1, move from room (1, 0) to room (1, 1) in one second.
# At time t == 2, move from room (1, 1) to room (1, 2) in one second.
# Example 3:
# Input: moveTime = [[0,1],[1,2]]
# Output: 3
# Constraints:
# 2 <= n == moveTime.length <= 50
# 2 <= m == moveTime[i].length <= 50
# 0 <= moveTime[i][j] <= 109

class Solution(object):
    def minTimeToReach(self, moveTime):
        """
        :type moveTime: List[List[int]]
        :rtype: int
        """
        n = len(moveTime)
        m = len(moveTime[0])
        dp = [[0] * m for _ in range(n)]
        dp[0][0] = moveTime[0][0]

        for i in range(n):
            for j in range(m):
                if i > 0:
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + 1)
                if j > 0:
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + 1)
                dp[i][j] = max(dp[i][j], moveTime[i][j])

        return dp[n-1][m-1]

