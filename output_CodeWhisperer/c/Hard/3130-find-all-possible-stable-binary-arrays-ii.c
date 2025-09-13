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
    const int MOD = 1000000007;
    int n = zero + one;
    int dp[1001][1001] = {0};
    
    // Base case - empty array
    dp[0][0] = 1;
    
    // For each length i
    for(int i = 0; i < n; i++) {
        // For each count of ones j
        for(int j = 0; j <= i && j < one; j++) {
            // For each count of zeros k
            int k = i - j;
            if(k <= zero) {
                // Can add 0 if zeros remaining
                if(k < zero) {
                    // Check if adding 0 violates limit constraint
                    int zeroLen = 0;
                    int validZero = 1;
                    for(int l = 1; l <= limit && i-l+1 >= 0; l++) {
                        if(j <= i-l+1) {
                            zeroLen++;
                            if(zeroLen > limit) {
                                validZero = 0;
                                break;
                            }
                        }
                    }
                    if(validZero) {
                        dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
                    }
                }
                
                // Can add 1 if ones remaining
                if(j < one) {
                    // Check if adding 1 violates limit constraint
                    int validOne = 1;
                    for(int l = 1; l <= limit && i-l+1 >= 0; l++) {
                        if(k <= i-l+1) {
                            if(l > limit) {
                                validOne = 0;
                                break;
                            }
                        }
                    }
                    if(validOne) {
                        dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
                    }
                }
            }
        }
    }
    
    return dp[n][one];
}    