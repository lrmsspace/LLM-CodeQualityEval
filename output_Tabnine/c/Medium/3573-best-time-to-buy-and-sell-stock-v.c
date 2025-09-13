/*
 You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.
 You are allowed to make at most k transactions, where each transaction can be either of the following:
 Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].
 Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].
 Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.
 Return the maximum total profit you can earn by making at most k transactions.
 Example 1:
 Input: prices = [1,7,9,8,2], k = 2
 Output: 14
 Explanation:
 We can make $14 of profit through 2 transactions:
 A normal transaction: buy the stock on day 0 for $1 then sell it on day 2 for $9.
 A short selling transaction: sell the stock on day 3 for $8 then buy back on day 4 for $2.
 Example 2:
 Input: prices = [12,16,19,19,8,1,19,13,9], k = 3
 Output: 36
 Explanation:
 We can make $36 of profit through 3 transactions:
 A normal transaction: buy the stock on day 0 for $12 then sell it on day 2 for $19.
 A short selling transaction: sell the stock on day 3 for $19 then buy back on day 4 for $8.
 A normal transaction: buy the stock on day 5 for $1 then sell it on day 6 for $19.
 Constraints:
 2 <= prices.length <= 103
 1 <= prices[i] <= 109
 1 <= k <= prices.length / 2
*/

long long maximumProfit(int* prices, int pricesSize, int k) {
    if (pricesSize <= 1) {
        return 0;
    }
    
    // Initialize two arrays to store the maximum profit at each transaction
    // dp[i][j] represents the maximum profit for the first i days and j transactions
    int** dp = (int**)malloc(sizeof(int*) * (pricesSize + 1));
    for (int i = 0; i <= pricesSize; i++) {
        dp[i] = (int*)malloc(sizeof(int) * (k + 1));
        for (int j = 0; j <= k; j++) {
            dp[i][j] = INT_MIN;
        }
    }
    
    // Initialize the first day's profit with 0
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[0][i] = INT_MIN;
    }
    dp[1][1] = prices[1] - prices[0];
    for (int j = 2; j <= k; j++) {
        dp[1][j] = INT_MIN;
    }
    // Calculate the maximum profit for the first i days and j transactions

    for (int i = 2; i <= pricesSize; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l < i; l++) {
                dp[i][j] = fmax(dp[i][j], dp[l][j - 1] + prices[i] - prices[l]);
            }
        }
    }
    
    // Return the maximum total profit
    long long maxProfit = INT_MIN;
    for (int i = 1; i <= k; i++) {
        maxProfit = fmax(maxProfit, dp[pricesSize][i]);
    }
    
    // Free the memory
    for (int i = 0; i <= pricesSize; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return maxProfit;
    
}