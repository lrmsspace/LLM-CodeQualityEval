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
    public int numberOfCombinations(String num) {
        int n = num.length();
        final int MOD = 1000000007;
        long[][] dp = new long[n + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
                if (j < i) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                }
            }
        }
        return (int) dp[n][n];        
    }
}