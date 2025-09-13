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

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9+7;
        vector<vector<vector<int>>> dp(zero+1, vector<vector<int>>(one+1, vector<int>(2,0)));
        for(int i=0;i<=zero;i++){
            for(int j=0;j<=one;j++){
                if(i==0 || j==0){
                    dp[i][j][0] = 1;
                    dp[i][j][1] = 1;
                }
                for(int k=1;k<=limit;k++){
                    if(i>=k){
                        dp[i][j][0] = (dp[i][j][0] + dp[i-k][j][1])%mod;
                    }
                    if(j>=k){
                        dp[i][j][1] = (dp[i][j][1] + dp[i][j-k][0])%mod;
                    }
                }
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1])%mod;        
    }
};