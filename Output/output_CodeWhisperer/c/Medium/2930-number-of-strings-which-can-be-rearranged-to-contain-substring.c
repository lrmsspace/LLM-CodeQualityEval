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

int stringCount(int n) {
    const int MOD = 1000000007;
    
    // If length less than 4, cannot form "leet"
    if (n < 4) return 0;
    
    // dp[i][mask] represents number of ways to form string of length i 
    // with mask representing which chars of "leet" are used
    long long dp[100001][16] = {0};
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < 16; mask++) {
            if (dp[i][mask] == 0) continue;
            
            // Add 'l' (bit 0)
            if ((mask & 1) == 0) {
                dp[i + 1][mask | 1] = (dp[i + 1][mask | 1] + dp[i][mask]) % MOD;
            }
            
            // Add 'e' (bits 1,2) 
            if ((mask & 2) == 0) {
                dp[i + 1][mask | 2] = (dp[i + 1][mask | 2] + dp[i][mask]) % MOD;
            }
            else if ((mask & 4) == 0 && (mask & 2)) {
                dp[i + 1][mask | 4] = (dp[i + 1][mask | 4] + dp[i][mask]) % MOD;
            }
            
            // Add 't' (bit 3)
            if ((mask & 8) == 0) {
                dp[i + 1][mask | 8] = (dp[i + 1][mask | 8] + dp[i][mask]) % MOD;
            }
            
            // Add any other lowercase letter
            dp[i + 1][mask] = (dp[i + 1][mask] + (dp[i][mask] * 22) % MOD) % MOD;
        }
    }
    
    long long ans = 0;
    // Sum up all valid masks that contain "leet"
    for (int mask = 0; mask < 16; mask++) {
        if ((mask & 15) == 15) {
            ans = (ans + dp[n][mask]) % MOD;
        }
    }
    
    return ans;
}    