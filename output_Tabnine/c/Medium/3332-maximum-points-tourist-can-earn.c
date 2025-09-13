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

int maxScore(int n, int k, int** stayScore, int stayScoreSize, int* stayScoreColSize, int** travelScore, int travelScoreSize, int* travelScoreColSize) {
    
    // Create a 2D dynamic programming table to store the maximum points
    int dp[k + 1][n];
    
    // Initialize the first day's maximum points
    for (int i = 0; i < n; i++) {
        dp[0][i] = stayScore[0][i];
    }
    // Iterate through the remaining days
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            // Calculate the maximum points for staying in the current city and moving to another city
            int stay = dp[i - 1][j];
            int travel = INT_MIN;
            for (int m = 0; m < n; m++) {
                if (m!= j) {
                    travel = max(travel, dp[i - 1][m] + travelScore[j][m]);
                }
            }
            // Update the maximum points for the current day
            dp[i][j] = max(stay, travel);
        }
    }
    
    // Return the maximum possible points
    return dp[k][0];
    
}