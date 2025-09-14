/**https://leetcode.com/problems/dice-roll-simulation/ */
//A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times.
//Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls. Since the answer may be too large, return it modulo 109 + 7.
//Two sequences are considered different if at least one element differs from each other.
// 
//Example 1:
//Input: n = 2, rollMax = [1,1,2,2,2,3]
//Output: 34
//Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.
//Example 2:
//Input: n = 2, rollMax = [1,1,1,1,1,1]
//Output: 30
//Example 3:
//Input: n = 3, rollMax = [1,1,1,2,2,3]
//Output: 181
// 
//Constraints:
//	1 <= n <= 5000
//	rollMax.length == 6
//	1 <= rollMax[i] <= 15
/**
 * @param {number} n
 * @param {number[]} rollMax
 * @return {number}
 */
var dieSimulator = function(n, rollMax) {
    const MOD = 10 ** 9 + 7;
    const dp = Array.from({ length: n + 1 }, () => Array.from({ length: 6 }, () => Array(16).fill(0)));
    
    for (let i = 1; i <= 6; i++) dp[1][i][1] = 1;
    
    for (let i = 2; i <= n; i++) {
        for (let j = 1; j <= 6; j++) {
            for (let k = 1; k <= rollMax[j - 1]; k++) {
                for (let l = 1; l <= 6; l++) {
                    if (l!== j) {
                        dp[i][j][k + 1] = (dp[i][j][k + 1] + dp[i - 1][l][k]) % MOD;
                    }
                }
            }
        }
    }
    
    let total = 0;
    for (let i = 1; i <= 6; i++) {
        total = (total + dp[n][i][rollMax[i - 1] + 1]) % MOD;
    }
    
    return total;
    
};