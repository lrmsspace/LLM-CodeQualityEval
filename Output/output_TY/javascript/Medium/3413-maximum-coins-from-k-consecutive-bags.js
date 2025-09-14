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

/**
 * @param {number[][]} coins
 * @param {number} k
 * @return {number}
 */
var maximumCoins = function(coins, k) {
    coins.sort((a,b) => b[1] - a[1]);   
    let ans = 0;
    for (let i = 0; i < coins.length; i++) {
        if (coins[i][1] - k >= coins[i][0]) {
            ans += coins[i][2];
            k -= coins[i][1] - coins[i][0];
        } else {
            ans += coins[i][2] * (coins[i][1] - k);
            break;
        }
    }
    return ans;
    
};