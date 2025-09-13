/**https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/ */
//There are n people and 40 types of hats labeled from 1 to 40.
//Given a 2D integer array hats, where hats[i] is a list of all hats preferred by the ith person.
//Return the number of ways that the n people wear different hats to each other.
//Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: hats = [[3,4],[4,5],[5]]
//Output: 1
//Explanation: There is only one way to choose hats given the conditions. 
//First person choose hat 3, Second person choose hat 4 and last one hat 5.
//Example 2:
//Input: hats = [[3,5,1],[3,5]]
//Output: 4
//Explanation: There are 4 ways to choose hats:
//(3,5), (5,3), (1,3) and (1,5)
//Example 3:
//Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
//Output: 24
//Explanation: Each person can choose hats labeled from 1 to 4.
//Number of Permutations of (1,2,3,4) = 24.
// 
//Constraints:
//	n == hats.length
//	1 <= n <= 10
//	1 <= hats[i].length <= 40
//	1 <= hats[i][j] <= 40
//	hats[i] contains a list of unique integers.
/**
 * @param {number[][]} hats
 * @return {number}
 */
var numberWays = function(hats) {
    const MOD = 1e9 + 7;
    const n = hats.length;
    const m = 40;
    const dp = Array(1 << n).fill(0).map(() => Array(m + 1).fill(0));
    dp[0][0] = 1;

    for (let mask = 0; mask < (1 << n); mask++) {
        for (let i = 0; i < m; i++) {
            if (dp[mask][i] === 0) continue;
            for (let j = 0; j < n; j++) {
                if ((mask & (1 << j)) === 0 && hats[j].includes(i + 1)) {
                    dp[mask | (1 << j)][i + 1] = (dp[mask | (1 << j)][i + 1] + dp[mask][i]) % MOD;
                }
            }
        }
    }

    let ans = 0;
    for (let i = 1; i <= m; i++) {
        ans = (ans + dp[(1 << n) - 1][i]) % MOD;
    }
    return ans;    
};