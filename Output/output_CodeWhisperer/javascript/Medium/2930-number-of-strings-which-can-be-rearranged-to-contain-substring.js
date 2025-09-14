/*
 You are given an integer n.
 A string s is called good if it contains only lowercase English characters and it is possible to rearrange the characters of s such that the new string contains "leet" as a substring.
 For example:
 The string "lteer" is good because we can rearrange it to form "leetr" .
 "letl" is not good because we cannot rearrange it to contain "leet" as a substring.
 Return the total number of good strings of length n.
 Since the answer may be large, return it modulo 109 + 7.
 A substring is a contiguous sequence of characters within a string.
 Example 1:
 Input: n = 4
 Output: 12
 Explanation: The 12 strings which can be rearranged to have "leet" as a substring are: "eelt", "eetl", "elet", "elte", "etel", "etle", "leet", "lete", "ltee", "teel", "tele", and "tlee".
 Example 2:
 Input: n = 10
 Output: 83943898
 Explanation: The number of strings with length 10 which can be rearranged to have "leet" as a substring is 526083947580. Hence the answer is 526083947580 % (109 + 7) = 83943898.
 Constraints:
 1 <= n <= 105
*/

/**
 * @param {number} n
 * @return {number}
 */
var stringCount = function(n) {
    const MOD = 1000000007;
    let dp = new Array(n + 1).fill(0).map(() => new Array(2).fill(0).map(() => new Array(2).fill(0).map(() => new Array(2).fill(0))));
    
    dp[0][0][0][0] = 1;
    
    for (let i = 1; i <= n; i++) {
        for (let e = 0; e <= 1; e++) {
            for (let l = 0; l <= 1; l++) {
                for (let t = 0; t <= 1; t++) {
                    for (let x = 0; x <= 1; x++) {
                        if (x == 0) {
                            dp[i][e][l][t] = (dp[i][e][l][t] + 23 * dp[i - 1][e][l][t]) % MOD;
                        } else {
                            if (e == 0) {
                                dp[i][1][l][t] = (dp[i][1][l][t] + dp[i - 1][e][l][t]) % MOD;
                            }
                            if (l == 0) {
                                dp[i][e][1][t] = (dp[i][e][1][t] + dp[i - 1][e][l][t]) % MOD;
                            }
                            if (t == 0) {
                                dp[i][e][l][1] = (dp[i][e][l][1] + dp[i - 1][e][l][t]) % MOD;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return dp[n][1][1][1];
            
};