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
    const total = matchsticks.reduce((acc, cur) => acc + cur, 0);
    if (total % 4 !== 0) return false;

    const side = total / 4;
    const dp = new Array(1 << matchsticks.length).fill(0);
    dp[0] = 0;
    for (let i = 0; i < (1 << matchsticks.length); i++) {
        if (dp[i] >= 0) {
            for (let j = 0; j < matchsticks.length; j++) {
                if (i & (1 << j)) continue;
                const next = dp[i] + matchsticks[j];
                if (next > side) {
                    dp[i | (1 << j)] = -1;
                } else if (next === side) {
                    dp[i | (1 << j)] = 0;
                } else {
                    dp[i | (1 << j)] = next;
                }
            }
        }
    }
    return dp[(1 << matchsticks.length) - 1] === 0;
};