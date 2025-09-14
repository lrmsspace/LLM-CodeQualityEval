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
    let n = power.length;
    let dp = new Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        let maxDamage = 0;
        for (let j = 0; j < i; j++) {
            maxDamage = Math.max(maxDamage, dp[j] + power[i] * (i - j));
        }
        dp[i] = maxDamage;
    }   
    return dp[n - 1];
    
};