/**https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/ */
//Given n orders, each order consists of a pickup and a delivery service.
//Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 
//Since the answer may be too large, return it modulo 10^9 + 7.
// 
//Example 1:
//Input: n = 1
//Output: 1
//Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
//Example 2:
//Input: n = 2
//Output: 6
//Explanation: All possible orders: 
//(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
//This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
//Example 3:
//Input: n = 3
//Output: 90
// 
//Constraints:
//	1 <= n <= 500
class Solution {
public:
    int countOrders(int n) {
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j] * (i - j)) % MOD;
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (i - j)) % MOD;
                }
            }
        }
        return dp[n][n / 2];       
    }
};