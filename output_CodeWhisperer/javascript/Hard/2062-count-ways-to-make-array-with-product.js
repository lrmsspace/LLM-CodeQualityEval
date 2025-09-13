/**https://leetcode.com/problems/count-ways-to-make-array-with-product/ */
//You are given a 2D integer array, queries. For each queries[i], where queries[i] = [ni, ki], find the number of different ways you can place positive integers into an array of size ni such that the product of the integers is ki. As the number of ways may be too large, the answer to the ith query is the number of ways modulo 109 + 7.
//Return an integer array answer where answer.length == queries.length, and answer[i] is the answer to the ith query.
// 
//Example 1:
//Input: queries = [[2,6],[5,1],[73,660]]
//Output: [4,1,50734910]
//Explanation: Each query is independent.
//[2,6]: There are 4 ways to fill an array of size 2 that multiply to 6: [1,6], [2,3], [3,2], [6,1].
//[5,1]: There is 1 way to fill an array of size 5 that multiply to 1: [1,1,1,1,1].
//[73,660]: There are 1050734917 ways to fill an array of size 73 that multiply to 660. 1050734917 modulo 109 + 7 = 50734910.
//Example 2:
//Input: queries = [[1,1],[2,2],[3,3],[4,4],[5,5]]
//Output: [1,2,3,10,5]
// 
//Constraints:
//	1 <= queries.length <= 104 
//	1 <= ni, ki <= 104
/**
 * @param {number[][]} queries
 * @return {number[]}
 */
var waysToFillArray = function(queries) {
    const MOD = 1000000007;
    const dp = new Array(10001).fill(0).map(() => new Array(15).fill(0));
    for (let i = 1; i <= 10000; i++) {
        for (let j = 1; j <= 14; j++) {
            if (i === 1 || j === 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
            }
        }
    }
    const ans = [];
    for (const [n, k] of queries) {
        let res = 1;
        for (let i = 2; i <= k; i++) {
            let count = 0;
            while (k % i === 0) {
                count++;
                k /= i;
            }
            if (count > 0) {
                res = (res * dp[n+count-1][count]) % MOD;
            }
        }
        ans.push(res);
    }
    return ans;
};