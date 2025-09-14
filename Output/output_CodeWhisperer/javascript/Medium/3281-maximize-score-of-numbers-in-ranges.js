/*
 You are given an array of integers start and an integer d, representing n intervals [start[i], start[i] + d].
 You are asked to choose n integers where the ith integer must belong to the ith interval. The score of the chosen integers is defined as the minimum absolute difference between any two integers that have been chosen.
 Return the maximum possible score of the chosen integers.
 Example 1:
 Input: start = [6,0,3], d = 2
 Output: 4
 Explanation:
 The maximum possible score can be obtained by choosing integers: 8, 0, and 4. The score of these chosen integers is min(|8 - 0|, |8 - 4|, |0 - 4|) which equals 4.
 Example 2:
 Input: start = [2,6,13,13], d = 5
 Output: 5
 Explanation:
 The maximum possible score can be obtained by choosing integers: 2, 7, 13, and 18. The score of these chosen integers is min(|2 - 7|, |2 - 13|, |2 - 18|, |7 - 13|, |7 - 18|, |13 - 18|) which equals 5.
 Constraints:
 2 <= start.length <= 105
 0 <= start[i] <= 109
 0 <= d <= 109
*/

/**
 * @param {number[]} start
 * @param {number} d
 * @return {number}
 */
var maxPossibleScore = function(start, d) {
    const n = start.length;
    const dp = new Array(n + 1).fill(0);
    
    start.sort((a, b) => a - b);
    
    for (let i = 1; i <= n; i++) {
        dp[i] = Math.min(d, start[i - 1] - start[0]);
        for (let j = 1; j < i; j++) {
            dp[i] = Math.max(dp[i], dp[j] + Math.min(d, start[i - 1] - start[j]));
        }
    }
    
    return dp[n];    
};