/*
 You are given 3 positive integers zero, one, and limit.
 A binary array arr is called stable if:
 The number of occurrences of 0 in arr is exactly zero.
 The number of occurrences of 1 in arr is exactly one.
 Each subarray of arr with a size greater than limit must contain both 0 and 1.
 Return the total number of stable binary arrays.
 Since the answer may be very large, return it modulo 109 + 7.
 Example 1:
 Input: zero = 1, one = 1, limit = 2
 Output: 2
 Explanation:
 The two possible stable binary arrays are [1,0] and [0,1].
 Example 2:
 Input: zero = 1, one = 2, limit = 1
 Output: 1
 Explanation:
 The only possible stable binary array is [1,0,1].
 Example 3:
 Input: zero = 3, one = 3, limit = 2
 Output: 14
 Explanation:
 All the possible stable binary arrays are [0,0,1,0,1,1], [0,0,1,1,0,1], [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], [0,1,1,0,0,1], [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], [1,0,1,0,0,1], [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], and [1,1,0,1,0,0].
 Constraints:
 1 <= zero, one, limit <= 1000
*/

int numberOfStableArrays(int zero, int one, int limit) {
    const int MOD = 1e9 + 7;
    int dp[zero + 1][one + 1][limit + 1];
    
    // Initialize the dp array
    for (int i = 0; i <= zero; i++) {
        for (int j = 0; j <= one; j++) {
            for (int k = 0; k <= limit; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    
    // Base case: one way to have an empty stable array
    dp[0][1][0] = 1;

    // Fill the dp array
    for (int z = 0; z <= zero; z++) {
        for (int o = 0; o <= one; o++) {
            for (int l = 0; l <= limit; l++) {
                if (o > 0) { // If we can place a '1'
                    dp[z][o][l] = (dp[z][o][l] + dp[z][o - 1][l]) % MOD;
                }
                if (z > 0 && l < limit) { // If we can place a '0'
                    dp[z][o][l + 1] = (dp[z][o][l + 1] + dp[z - 1][o][l]) % MOD;
                }
            }
        }
    }

    // Sum up all valid stable arrays
    int result = 0;
    for (int l = 0; l <= limit; l++) {
        result = (result + dp[zero][one][l]) % MOD;
    }

    return result;    
}