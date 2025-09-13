/*
 You are given integers n, m, and k.
 There are two logs of lengths n and m units, which need to be transported in three trucks where each truck can carry one log with length at most k units.
 You may cut the logs into smaller pieces, where the cost of cutting a log of length x into logs of length len1 and len2 is cost = len1 * len2 such that len1 + len2 = x.
 Return the minimum total cost to distribute the logs onto the trucks. If the logs don't need to be cut, the total cost is 0.
 Example 1:
 Input: n = 6, m = 5, k = 5
 Output: 5
 Explanation:
 Cut the log with length 6 into logs with length 1 and 5, at a cost equal to 1 * 5 == 5. Now the three logs of length 1, 5, and 5 can fit in one truck each.
 Example 2:
 Input: n = 4, m = 4, k = 6
 Output: 0
 Explanation:
 The two logs can fit in the trucks already, hence we don't need to cut the logs.
 Constraints:
 2 <= k <= 105
 1 <= n, m <= 2 * k
 The input is generated such that it is always possible to transport the logs.
*/

/**
 * @param {number} n
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
var minCuttingCost = function(n, m, k) {
    let dp = new Array(n+1).fill(0).map(() => new Array(k+1).fill(Infinity));
    for (let i = 1; i <= n; i++) {
        dp[i][1] = i-1;
    }
    for (let i = 2; i <= k; i++) {
        for (let j = i; j <= n; j++) {
            for (let x = i-1; x < j; x++) {
                dp[j][i] = Math.min(dp[j][i], dp[x][i-1] + (j-x)*m);
            }
        }
    }
    return dp[n][k];
    
};