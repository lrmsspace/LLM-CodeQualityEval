/**https://leetcode.com/problems/number-of-ways-to-separate-numbers/ */
//You wrote down many positive integers in a string called num. However, you realized that you forgot to add commas to seperate the different numbers. You remember that the list of integers was non-decreasing and that no integer had leading zeros.
//Return the number of possible lists of integers that you could have written down to get the string num. Since the answer may be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: num = "327"
//Output: 2
//Explanation: You could have written down the numbers:
//3, 27
//327
//Example 2:
//Input: num = "094"
//Output: 0
//Explanation: No numbers can have leading zeros and all numbers must be positive.
//Example 3:
//Input: num = "0"
//Output: 0
//Explanation: No numbers can have leading zeros and all numbers must be positive.
// 
//Constraints:
//	1 <= num.length <= 3500
//	num consists of digits '0' through '9'.
class Solution {
public:
    int numberOfCombinations(string num) {
        int n = num.size();
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][i] = 1;
            sum[i][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (num[i - 1] == '0') {
                    dp[i][j] = 0;
                } else {
                    int len = j - i;
                    int l = i - len;
                    int r = i - 1;
                    if (l < 1 || num.substr(l, len) <= num.substr(r, len)) {
                        dp[i][j] = sum[i - 1][i - 1];
                    } else {
                        dp[i][j] = (sum[i - 1][i - 1] - sum[l - 1][i - 1] + mod) % mod;
                    }
                }
                sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
            }
        }
        return sum[n][n];     
    }
};