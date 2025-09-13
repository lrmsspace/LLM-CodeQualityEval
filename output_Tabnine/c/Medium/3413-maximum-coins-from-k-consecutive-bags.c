/*
 There are an infinite amount of bags on a number line, one bag for each coordinate. Some of these bags contain coins.
 You are given a 2D array coins, where coins[i] = [li, ri, ci] denotes that every bag from li to ri contains ci coins.
 The segments that coins contain are non-overlapping.
 You are also given an integer k.
 Return the maximum amount of coins you can obtain by collecting k consecutive bags.
 Example 1:
 Input: coins = [[8,10,1],[1,3,2],[5,6,4]], k = 4
 Output: 10
 Explanation:
 Selecting bags at positions [3, 4, 5, 6] gives the maximum number of coins: 2 + 0 + 4 + 4 = 10.
 Example 2:
 Input: coins = [[1,10,3]], k = 2
 Output: 6
 Explanation:
 Selecting bags at positions [1, 2] gives the maximum number of coins: 3 + 3 = 6.
 Constraints:
 1 <= coins.length <= 105
 1 <= k <= 109
 coins[i] == [li, ri, ci]
 1 <= li <= ri <= 109
 1 <= ci <= 1000
 The given segments are non-overlapping.
*/

long long maximumCoins(int** coins, int coinsSize, int* coinsColSize, int k) {

    // Initialize dp array with 0s
    long long* dp = (long long*)malloc(k * sizeof(long long));
    for (int i = 0; i < k; i++) {
        dp[i] = 0;
    }
    
    // Iterate through the coins and update dp array
    for (int i = 0; i < coinsSize; i++) {
        int left = coins[i][0] - 1;
        int right = coins[i][1] - 1;
        int coinsCount = coins[i][2];
        
        // Update dp array using the maximum coins from the previous bags
        for (int j = right; j >= left; j--) {
            dp[j] = fmax(dp[j], dp[j - 1] + coinsCount);
        }
    }
    
    // Return the maximum coins obtained by collecting k consecutive bags
    long long result = 0;
    for (int i = 0; i < k; i++) {
        result = fmax(result, dp[i]);
    }   
    free(dp);
    return result;
    
}