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
    
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    long long ans = 0;
    int dp[powerSize][powerSize];
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < powerSize; i++) {
        dp[i][i] = power[i];
    }
    for (i = 0; i < powerSize - 1; i++) {
        dp[i][i + 1] = power[i] + power[i + 1];
    }
    for (i = 2; i < powerSize; i++) {
        for (j = 0; j < powerSize - i; j++) {
            dp[j][j + i] = max(dp[j][j + i - 1] + power[j + i], dp[j + 1][j + i] + power[j]);
        }
    }
    return dp[0][powerSize - 1];
}