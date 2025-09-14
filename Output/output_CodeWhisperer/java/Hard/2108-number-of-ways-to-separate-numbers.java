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
        int[][] dp = new int[n][n];
        int mod = 1000000007;
        for(int i = 0; i < n; i++) {
            dp[i][i] = num.charAt(i) == '0' ? 0 : 1;
        }
        for(int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(num.charAt(i) == '0') {
                    dp[i][j] = 0;
                } else if(i == 0) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                    if(num.substring(i, j + 1).compareTo(num.substring(i - 1, j)) >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                    }
                    for(int k = i - 1; k >= 0; k--) {
                        if(num.substring(k, j + 1).compareTo(num.substring(k, i)) >= 0) {
                            dp[i][j] = (dp[i][j] + dp[k][i - 1]) % mod;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return dp[n - 1][n - 1];
        
    }
}