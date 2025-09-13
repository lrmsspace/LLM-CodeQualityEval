/**https://leetcode.com/problems/matchsticks-to-square/ */
//You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
//Return true if you can make this square and false otherwise.
// 
//Example 1:
//Input: matchsticks = [1,1,2,2,2]
//Output: true
//Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
//Example 2:
//Input: matchsticks = [3,3,3,3,4]
//Output: false
//Explanation: You cannot find a way to form a square with all the matchsticks.
// 
//Constraints:
//	1 <= matchsticks.length <= 15
//	1 <= matchsticks[i] <= 108
/**
 * @param {number[]} matchsticks
 * @return {boolean}
 */
var makesquare = function(matchsticks) {
    const sum = matchsticks.reduce((a, b) => a + b, 0);
    if (sum % 4 !== 0) return false;
    const target = sum / 4;
    const dp = new Array(1 << matchsticks.length).fill(false);
    dp[0] = true;
    for (let mask = 0; mask < (1 << matchsticks.length); mask++) {
        if (!dp[mask]) continue;
        for (let i = 0; i < matchsticks.length; i++) {
            if (matchsticks[i] > target) continue;
            if (((mask >> i) & 1) === 0 && dp[mask] && dp[mask ^ (1 << i)] === false)
                dp[mask ^ (1 << i)] = true;
            else if (matchsticks[i] + target === sum) return true;
        }
    }
    return dp[(1 << matchsticks.length) - 1];
};