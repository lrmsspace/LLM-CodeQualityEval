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
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> prefix(n, 0);
        prefix[0] = num[0] - '0';
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * 10 + num[i] - '0';
        }
        dp[0][0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][i] = 1;
            for (int j = 1; j <= i; j++) {
                if (num[i - j + 1] == '0') {
                    continue;
                }
                int num1 = prefix[i - j];
                int num2 = prefix[i] - prefix[i - j];
                if (num1 <= num2) {
                    dp[i][j] = (dp[i][j] + dp[i - j][j]) % 1000000007;
                }
                dp[i][j] = (dp[i][j] + dp[i - j][j - 1]) % 1000000007;
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = (result + dp[n - 1][i]) % 1000000007;
        }
        return result;        
    }
};