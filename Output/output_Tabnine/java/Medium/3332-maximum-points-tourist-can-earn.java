/*
 You are given two integers, n and k, along with two 2D integer arrays, stayScore and travelScore.
 A tourist is visiting a country with n cities, where each city is directly connected to every other city. The tourist's journey consists of exactly k 0-indexed days, and they can choose any city as their starting point.
 Each day, the tourist has two choices:
 Stay in the current city: If the tourist stays in their current city curr during day i, they will earn stayScore[i][curr] points.
 Move to another city: If the tourist moves from their current city curr to city dest, they will earn travelScore[curr][dest] points.
 Return the maximum possible points the tourist can earn.
 Example 1:
 Input: n = 2, k = 1, stayScore = [[2,3]], travelScore = [[0,2],[1,0]]
 Output: 3
 Explanation:
 The tourist earns the maximum number of points by starting in city 1 and staying in that city.
 Example 2:
 Input: n = 3, k = 2, stayScore = [[3,4,2],[2,1,2]], travelScore = [[0,2,1],[2,0,4],[3,2,0]]
 Output: 8
 Explanation:
 The tourist earns the maximum number of points by starting in city 1, staying in that city on day 0, and traveling to city 2 on day 1.
 Constraints:
 1 <= n <= 200
 1 <= k <= 200
 n == travelScore.length == travelScore[i].length == stayScore[i].length
 k == stayScore.length
 1 <= stayScore[i][j] <= 100
 0 <= travelScore[i][j] <= 100
 travelScore[i][i] == 0
*/

class Solution {
    public int maxScore(int n, int k, int[][] stayScore, int[][] travelScore) {

        // Initialize a 2D dp array to store the maximum points the tourist can earn
        int[][] dp = new int[k + 1][n];
        
        // Initialize the first day's maximum points by staying in the current city
        for (int i = 0; i < n; i++) {
            dp[1][i] = stayScore[0][i];
        }
        // Calculate the maximum points for each subsequent day
        for (int day = 2; day <= k; day++) {
            for (int city = 0; city < n; city++) {
                // Find the maximum points from the previous day by staying in the current city or moving to another city
                int maxPoints = 0;
                for (int prevCity = 0; prevCity < n; prevCity++) {
                    maxPoints = Math.max(maxPoints, dp[day - 1][prevCity] + travelScore[prevCity][city]);
                }
                // Update the maximum points for the current day by staying in the current city or moving to another city
                dp[day][city] = Math.max(dp[day][city], stayScore[day - 1][city]);
                dp[day][city] = Math.max(dp[day][city], maxPoints);
            }
        }
        // Return the maximum possible points the tourist can earn
        return Arrays.stream(dp[k]).max().getAsInt();
        
    }
}