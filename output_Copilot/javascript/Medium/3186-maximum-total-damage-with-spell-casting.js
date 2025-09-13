/*
 A magician has various spells.
 You are given an array power, where each element represents the damage of a spell. Multiple spells can have the same damage value.
 It is a known fact that if a magician decides to cast a spell with a damage of power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.
 Each spell can be cast only once.
 Return the maximum possible total damage that a magician can cast.
 Example 1:
 Input: power = [1,1,3,4]
 Output: 6
 Explanation:
 The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.
 Example 2:
 Input: power = [7,1,6,6]
 Output: 13
 Explanation:
 The maximum possible damage of 13 is produced by casting spells 1, 2, 3 with damage 1, 6, 6.
 Constraints:
 1 <= power.length <= 105
 1 <= power[i] <= 109
*/

/**
 * @param {number[]} power
 * @return {number}
 */
var maximumTotalDamage = function(power) {
    const n = power.length;
    if (n === 0) return 0;

    // Sort the power array
    power.sort((a, b) => a - b);

    // Initialize dp array
    const dp = Array(n).fill(0);
    dp[0] = power[0];

    for (let i = 1; i < n; i++) {
        dp[i] = dp[i - 1]; // Case when we do not take the current spell
        if (i > 1 && power[i] - power[i - 2] > 2) {
            dp[i] = Math.max(dp[i], dp[i - 2] + power[i]); // Case when we take the current spell
        } else if (i === 1 || power[i] - power[i - 1] > 2) {
            dp[i] = Math.max(dp[i], power[i]); // Case when we take the current spell and the previous one is not adjacent
        }
    }

    return dp[n - 1];    
};