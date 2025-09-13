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
        // Create a map to store the number of coins at each position
        map<int, long long> positionCoins;
        
        // Fill the map with coins information
        for (const auto& segment : coins) {
            int l = segment[0];
            int r = segment[1];
            int c = segment[2];
            positionCoins[l] += c;
            positionCoins[r + 1] -= c;
        }
        
        // Use a prefix sum to calculate the number of coins at each position
        long long currentCoins = 0;
        vector<pair<int, long long>> positions;
        for (auto& [pos, c] : positionCoins) {
            currentCoins += c;
            positions.push_back({pos, currentCoins});
        }
        
        // Find the maximum coins collected over k consecutive positions
        long long maxCoins = 0, windowCoins = 0;
        int n = positions.size();
        for (int i = 0, j = 0; i < n; ++i) {
            windowCoins += positions[i].second;
            // Maintain a window of size k
            if (positions[i].first - positions[j].first == k) {
                maxCoins = max(maxCoins, windowCoins);
                windowCoins -= positions[j++].second;
            }
        }
        
        return maxCoins;

    }
};