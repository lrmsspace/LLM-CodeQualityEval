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
double soupServings(int n) {
    if (n >= 4800) {
        return 1.0;
    }
    double dp[200][200];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0.5;
    for (int i = 1; i <= 200; i++) {
        dp[0][i] = 1.0;
    }
    int serve[5] = {100, 75, 50, 25};
    for (int i = 1; i <= n / 25 + (n % 25 != 0); i++) {
        for (int j = 1; j <= n / 25 + (n % 25 != 0); j++) {
            double p = 0.0;
            for (int k = 0; k < 4; k++) {
                int a = i - (serve[k] > 100 ? 100 : serve[k]) / 25;
                int b = j - (serve[k] > 75 ? 75 : serve[k] > 50 ? 50 : serve[k] > 25 ? 25 : 0) / 25;
                p += dp[max(0, a)][max(0, b)];
            }
            dp[i][j] = 0.25 * p;
        }
    }
    return dp[n / 25 + (n % 25 != 0)][n / 25 + (n % 25 != 0)];
}