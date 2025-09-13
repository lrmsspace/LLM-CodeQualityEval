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
        
        sort(coins.begin(), coins.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        long long ans = 0;
        int i = 0;
        
        while (k > 0 && i < coins.size()) {
            int j = i;
            while (j < coins.size() && coins[j][1] == coins[i][1]) {
                j++;
            }
            
            int count = j - i;
            int take = min(count, k);
            ans += take * coins[i][2];
            k -= take;
            i = j;
        }
        
        return ans;
    }
};