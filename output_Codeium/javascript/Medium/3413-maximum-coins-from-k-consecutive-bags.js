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
    const events = [];
    for (const [li, ri, ci] of coins) {
        events.push([li, ci]);
        events.push([ri + 1, -ci]);
    }
    events.sort((a, b) => a[0] - b[0]);

    let maxCoins = 0, currentCoins = 0, prevPosition = 0;
    const coinCounts = [];

    for (const [position, value] of events) {
        if (position != prevPosition) {
            coinCounts.push([prevPosition, currentCoins]);
            prevPosition = position;
        }
        currentCoins += value;
    }

    let left = 0, right = 0, currentSum = 0;
    while (right < coinCounts.length) {
        currentSum += (coinCounts[right][0] - coinCounts[right - 1][0]) * coinCounts[right - 1][1];
        while (coinCounts[right][0] - coinCounts[left][0] >= k) {
            currentSum -= (coinCounts[left + 1][0] - coinCounts[left][0]) * coinCounts[left][1];
            left++;
        }
        maxCoins = Math.max(maxCoins, currentSum);
        right++;
    }

    return maxCoins;

};