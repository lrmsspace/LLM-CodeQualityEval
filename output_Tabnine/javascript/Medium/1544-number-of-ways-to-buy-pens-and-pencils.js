/**https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/ */
//You are given an integer total indicating the amount of money you have. You are also given two integers cost1 and cost2 indicating the price of a pen and pencil respectively. You can spend part or all of your money to buy multiple quantities (or none) of each kind of writing utensil.
//Return the number of distinct ways you can buy some number of pens and pencils.
// 
//Example 1:
//Input: total = 20, cost1 = 10, cost2 = 5
//Output: 9
//Explanation: The price of a pen is 10 and the price of a pencil is 5.
//- If you buy 0 pens, you can buy 0, 1, 2, 3, or 4 pencils.
//- If you buy 1 pen, you can buy 0, 1, or 2 pencils.
//- If you buy 2 pens, you cannot buy any pencils.
//The total number of ways to buy pens and pencils is 5 + 3 + 1 = 9.
//Example 2:
//Input: total = 5, cost1 = 10, cost2 = 10
//Output: 1
//Explanation: The price of both pens and pencils are 10, which cost more than total, so you cannot buy any writing utensils. Therefore, there is only 1 way: buy 0 pens and 0 pencils.
// 
//Constraints:
//	1 <= total, cost1, cost2 <= 106
/**
 * @param {number} total
 * @param {number} cost1
 * @param {number} cost2
 * @return {number}
 */
var waysToBuyPensPencils = function(total, cost1, cost2) {
    // Initialize dp array with 0s
    const dp = new Array(total + 1).fill(0);
    
    // Base cases: if total is less than cost1 or cost2, then no ways to buy
    if (total < cost1) return 0;
    if (total < cost2) return 0;
    
    // Initialize base cases: if total is equal to cost1 or cost2, then only 1 way to buy
    dp[cost1] = 1;
    dp[cost2] = 1;
    
    // Fill the dp array
    for (let i = cost1 + 1; i <= total; i++) {
        dp[i] += dp[i - cost1];
        if (i >= cost2) dp[i] += dp[i - cost2];
    }
    
    // Return the total number of ways to buy
    return dp[total];
    
};