/**https://leetcode.com/problems/soup-servings/ */
//There are two types of soup: type A and type B. Initially, we have n ml of each type of soup. There are four kinds of operations:
//	Serve 100 ml of soup A and 0 ml of soup B,
//	Serve 75 ml of soup A and 25 ml of soup B,
//	Serve 50 ml of soup A and 50 ml of soup B, and
//	Serve 25 ml of soup A and 75 ml of soup B.
//When we serve some soup, we give it to someone, and we no longer have it. Each turn, we will choose from the four operations with an equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as possible. We stop once we no longer have some quantity of both types of soup.
//Note that we do not have an operation where all 100 ml's of soup B are used first.
//Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time. Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: n = 50
//Output: 0.62500
//Explanation: If we choose the first two operations, A will become empty first.
//For the third operation, A and B will become empty at the same time.
//For the fourth operation, B will become empty first.
//So the total probability of A becoming empty first plus half the probability that A and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.
//Example 2:
//Input: n = 100
//Output: 0.71875
// 
//Constraints:
//	0 <= n <= 109
class Solution {
public:
    double soupServings(int n) {
        // Define a 3D dp array with dimensions (n+25, n+25, 2)
        vector<vector<vector<double>>> dp(n+26, vector<vector<double>>(n+26, vector<double>(2, 0.0)));
        
        // Initialize base cases
        dp[0][0][0] = 1.0; // Both soup types are empty
        dp[0][0][1] = 1.0; // Only soup A is empty
        dp[0][n+1][0] = 1.0; // Only soup B is empty
        
        // Calculate dp values iteratively
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k < 2; ++k) {
                    // Perform all four operations
                    for (int x = 0; x <= 2; ++x) {
                        for (int y = 0; y <= 2; ++y) {
                            // Calculate the remaining volume of soup after performing the operation
                            int remainingA = max(0, i - x - 25);
                            int remainingB = max(0, j - y - 25);
                            // Update the dp value
                            dp[i][j][k] += 0.25 * (dp[remainingA][remainingB][k] + dp[remainingA][j][!k] + dp[i][remainingB][!k] + dp[i][j][k]);
                        }
                    }
                }
            }
        }
        
        // Return the probability that soup A will be empty first
        return dp[n][0][0];
    }
};