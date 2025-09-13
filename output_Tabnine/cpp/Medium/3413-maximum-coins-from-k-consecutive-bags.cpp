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

class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        // Sort the coins based on the rightmost coordinate
        sort(coins.begin(), coins.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        // Initialize the prefix sum array
        vector<long long> prefixSum(coins.size() + 1);
        for (int i = 1; i <= coins.size(); ++i) {
            prefixSum[i] = prefixSum[i - 1] + coins[i - 1][2];
        }
        
        // Initialize the dp array
        vector<long long> dp(k + 1, 0);
        // Iterate from the rightmost coordinate to the leftmost coordinate     
        for (int i = coins.size(); i >= 1; --i) {
            for (int j = 1; j <= k && j + coins[i - 1][0] - 1 <= coins.size(); ++j) {
                // Calculate the maximum coins obtainable by selecting the current bag and the previous k bags
                dp[j] = max(dp[j], dp[j - 1] + prefixSum[i + j - 1] - prefixSum[i - 1]);
            }
        }
        
        // Return the maximum coins obtainable by selecting k consecutive bags
        return dp[k];
        
    }
};