/**https://leetcode.com/problems/numbers-with-repeated-digits/ */
//Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.
// 
//Example 1:
//Input: n = 20
//Output: 1
//Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
//Example 2:
//Input: n = 100
//Output: 10
//Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
//Example 3:
//Input: n = 1000
//Output: 262
// 
//Constraints:
//	1 <= n <= 109
/**
 * @param {number} n
 * @return {number}
 */
var numDupDigitsAtMostN = function(n) {
    let s = n.toString();
    let len = s.length;
    let ans = 0;
    let dp = new Array(len).fill(0).map(() => new Array(2).fill(0));
    dp[0][0] = 1;
    for (let i = 1; i < len; i++) {
        dp[i][0] = dp[i - 1][0] * 9;
        dp[i][1] = dp[i - 1][1] * 9;
    }
    for (let i = 1; i < len; i++) {
        dp[i][1] += dp[i - 1][0];
   }
   for (let i = 1; i < len; i++) {
       if (s[i] == s[i - 1]) {
           dp[i][0] = dp[i - 1][0];
           dp[i][1] = dp[i - 1][1];
       }
       if (s[i] < s[i - 1]) {
           dp[i][0] = 0;
           dp[i][1] = dp[i - 1][0];
       }
   }
   return dp[len - 1][0];
};