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

long long maximumTotalDamage(int* power, int powerSize) {
    long long* dp = (long long*)calloc(2001, sizeof(long long));
    for (int i = 0; i < powerSize; i++) {
        dp[power[i]] += power[i];
    }

    for (int i = 0; i < 2001; i++) {
        if (i - 1 >= 0) {
            dp[i] = fmax(dp[i], dp[i - 1]);
        }
        if (i - 2 >= 0) {
            dp[i] = fmax(dp[i], dp[i - 2]);
        }
    }

    long long result = 0;
    for (int i = 0; i < 2001; i++) {
        result = fmax(result, dp[i]);
    }

    free(dp);
    return result;
}