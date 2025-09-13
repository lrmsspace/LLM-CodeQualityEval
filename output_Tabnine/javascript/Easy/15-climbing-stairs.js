/**https://leetcode.com/problems/climbing-stairs/ */
//You are climbing a staircase. It takes n steps to reach the top.
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// 
//Example 1:
//Input: n = 2
//Output: 2
//Explanation: There are two ways to climb to the top.
//1. 1 step + 1 step
//2. 2 steps
//Example 2:
//Input: n = 3
//Output: 3
//Explanation: There are three ways to climb to the top.
//1. 1 step + 1 step + 1 step
//2. 1 step + 2 steps
//3. 2 steps + 1 step
// 
//Constraints:
//	1 <= n <= 45
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    // Initialize a dp array to store the number of distinct ways to reach each step
    let dp = new Array(n + 1).fill(0);
    
    // Base cases
    dp[0] = 1;
    dp[1] = 1;
    
    // Iterate through the steps from 2 to n
    for (let i = 2; i <= n; i++) {
        // The number of distinct ways to reach step i is the sum of the number of distinct ways to reach step i-1 and step i-2
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    // Return the number of distinct ways to reach the top
    return dp[n];
    
};