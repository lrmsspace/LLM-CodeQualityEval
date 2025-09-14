/**https://leetcode.com/problems/ugly-number-ii/ */
//An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
//Given an integer n, return the nth ugly number.
// 
//Example 1:
//Input: n = 10
//Output: 12
//Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
//Example 2:
//Input: n = 1
//Output: 1
//Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
// 
//Constraints:
//	1 <= n <= 1690
/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function(n) {
    let dp = new Array(n + 1).fill(1);
    let a = 0, b = 0, c = 0;
    for (let i = 1; i <= n; i++) {
        dp[i] = Math.min(dp[a] * 2, dp[b] * 3, dp[c] * 5);
        if (dp[i] === dp[a] * 2) a++;
        if (dp[i] === dp[b] * 3) b++;
        if (dp[i] === dp[c] * 5) c++;
    }
    return dp[n];
    
};  