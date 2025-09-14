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
    int n = coinsSize;
    int* bags = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int* bag = coins[i];
        int left = bag[0];
        int right = bag[1];
        int coins = bag[2];
        for (int j = left - 1; j < right; j++) {
            bags[j] += coins;
        }
    }
    long long maxCoins = 0;
    long long windowCoins = 0;
    for (int i = 0; i < k; i++) {
        windowCoins += bags[i];
    }
    maxCoins = windowCoins;
    for (int i = k; i < n; i++) {
        windowCoins += bags[i] - bags[i - k];
        maxCoins = fmax(maxCoins, windowCoins);
    }
    free(bags);
    return maxCoins;
}