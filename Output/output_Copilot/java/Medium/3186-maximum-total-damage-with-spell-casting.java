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

class Solution {
    public long maximumTotalDamage(int[] power) {
        long[] dp = new long[100001];
        int maxPower = 0;

        // Count the frequency of each power value
        for (int p : power) {
            maxPower = Math.max(maxPower, p);
            dp[p]++;
        }

        // Dynamic programming to calculate maximum damage
        for (int i = 1; i <= maxPower; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + i * dp[i]);
        }

        return dp[maxPower];        
    }
}