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
        int MOD = (int) 1e9 + 7;
        int n = num.length();
        int[] dp = new int[n + 1];
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            int digit = num.charAt(i - 1) - '0';
            int prev = i - 2 >= 0? dp[i - 2] : 0;
            
            if (digit > 0) {
                dp[i] = (dp[i] + prev) % MOD;
            }
            
            if (i >= 2 && num.charAt(i - 2) == '1' && digit <= 9) {
                dp[i] = (dp[i] + dp[i - 1]) % MOD;
            }
            
            if (i >= 3 && num.charAt(i - 3) == '2' && (digit >= 0 && digit <= 6)) {
                dp[i] = (dp[i] + dp[i - 1]) % MOD;
            }
        }
        
        return dp[n];
    }
}