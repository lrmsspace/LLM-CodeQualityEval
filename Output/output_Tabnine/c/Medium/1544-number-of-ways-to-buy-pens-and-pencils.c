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
long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    // Initialize a 2D dp array with size (total + 1) x (cost1 + 1) x (cost2 + 1)
    // dp[i][j][k] represents the number of ways to buy i pens, j pencils, and k erasers
    long long[][][] dp = new long long[total + 1][cost1 + 1][cost2 + 1];
    
    // Initialize the base cases
    // If total money is 0, there is only 1 way to buy 0 pens, 0 pencils, and 0 erasers
    for (int i = 0; i <= cost1; i++) {
        for (int j = 0; j <= cost2; j++) {
            dp[0][i][j] = 1;
        }
    }
    
    // Fill the dp array using dynamic programming
    for (int i = 1; i <= total; i++) {
        for (int j = 1; j <= cost1; j++) {
            for (int k = 1; k <= cost2; k++) {
                // Calculate the number of ways to buy i pens, j pencils, and k erasers
                // Either buy 0 of each item or buy 1 of each item
                dp[i][j][k] = dp[i][j][k] + dp[i - cost1][j][k] + dp[i][j - cost2][k] + dp[i][j][k - cost2];
            }
        }
    }
    
    // Return the number of distinct ways to buy some number of pens and pencils
    return dp[total][cost1][cost2];
    
}