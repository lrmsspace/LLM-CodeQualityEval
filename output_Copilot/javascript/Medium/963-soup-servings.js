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
/**
 * @param {number} n
 * @return {number}
 */
var soupServings = function(n) {
    if (n > 5000) return 1; // If n is large enough, the probability approaches 1.
    const dp = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));
    dp[0][0] = 0.5; // Base case: both soups empty at the same time.
    
    for (let i = 0; i <= n; i++) {
        for (let j = 0; j <= n; j++) {
            if (i === 0 && j === 0) continue;
            let prob = 0;
            if (i >= 100) prob += dp[i - 100][j] * 0.25;
            else if (i > 0) prob += dp[0][j] * 0.25;
            
            if (i >= 75 && j >= 25) prob += dp[i - 75][j - 25] * 0.25;
            else if (i > 0 && j > 0) prob += dp[0][j] * 0.25;
            
            if (i >= 50 && j >= 50) prob += dp[i - 50][j - 50] * 0.25;
            else if (i > 0 && j > 0) prob += dp[0][j] * 0.25;
            
            if (i >= 25 && j >= 75) prob += dp[i - 25][j - 75] * 0.25;
            else if (i > 0 && j > 0) prob += dp[0][j] * 0.25;
            
            dp[i][j] = prob;
        }
    }
    
    return dp[n][n];    
};