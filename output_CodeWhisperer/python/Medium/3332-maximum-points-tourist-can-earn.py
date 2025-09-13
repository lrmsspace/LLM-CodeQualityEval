# You are given two integers, n and k, along with two 2D integer arrays, stayScore and travelScore.
# A tourist is visiting a country with n cities, where each city is directly connected to every other city. The tourist's journey consists of exactly k 0-indexed days, and they can choose any city as their starting point.
# Each day, the tourist has two choices:
# Stay in the current city: If the tourist stays in their current city curr during day i, they will earn stayScore[i][curr] points.
# Move to another city: If the tourist moves from their current city curr to city dest, they will earn travelScore[curr][dest] points.
# Return the maximum possible points the tourist can earn.
# Example 1:
# Input: n = 2, k = 1, stayScore = [[2,3]], travelScore = [[0,2],[1,0]]
# Output: 3
# Explanation:
# The tourist earns the maximum number of points by starting in city 1 and staying in that city.
# Example 2:
# Input: n = 3, k = 2, stayScore = [[3,4,2],[2,1,2]], travelScore = [[0,2,1],[2,0,4],[3,2,0]]
# Output: 8
# Explanation:
# The tourist earns the maximum number of points by starting in city 1, staying in that city on day 0, and traveling to city 2 on day 1.
# Constraints:
# 1 <= n <= 200
# 1 <= k <= 200
# n == travelScore.length == travelScore[i].length == stayScore[i].length
# k == stayScore.length
# 1 <= stayScore[i][j] <= 100
# 0 <= travelScore[i][j] <= 100
# travelScore[i][i] == 0

class Solution(object):
    def maxScore(self, n, k, stayScore, travelScore):
        """
        :type n: int
        :type k: int
        :type stayScore: List[List[int]]
        :type travelScore: List[List[int]]
        :rtype: int
        """
        # Initialize a 2D array to store the maximum points for each day and city
        dp = [[0] * n for _ in range(k + 1)]

        # Base case: On the first day, the maximum points are the stayScore of each city
        for i in range(n):
            dp[0][i] = stayScore[0][i]

        # Iterate through each day
        for day in range(1, k + 1):
            # Iterate through each city
            for city in range(n):
                # Calculate the maximum points for staying in the current city
                stay = dp[day - 1][city] + stayScore[day][city]

                # Calculate the maximum points for moving to another city
                move = 0
                for prev_city in range(n):
                    if prev_city != city:
                        move = max(move, dp[day - 1][prev_city] + travelScore[prev_city][city])

                # Store the maximum points for the current day and city
                dp[day][city] = max(stay, move)

        # Return the maximum points for the last day
        return max(dp[k])        