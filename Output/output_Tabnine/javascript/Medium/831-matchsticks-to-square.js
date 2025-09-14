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
    const total = matchsticks.reduce((sum, m) => sum + m, 0);
    if (total % 4!== 0) return false;
    
    const target = total / 4;
    const dp = Array(1 << matchsticks.length).fill(false);
    dp[0] = true;
    
    for (let i = 0; i < matchsticks.length; i++) {
        for (let j = (1 << matchsticks.length) - 1; j >= 0; j--) {
            if (dp[j] && matchsticks[i] <= target) {
                dp[j | (1 << i)] = true;
            }
        }
    }
    
    return dp[(1 << matchsticks.length) - 1];
    
};