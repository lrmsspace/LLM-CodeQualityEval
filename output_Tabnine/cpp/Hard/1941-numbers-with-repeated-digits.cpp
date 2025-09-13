/**https://leetcode.com/problems/numbers-with-repeated-digits/ */
//Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.
// 
//Example 1:
//Input: n = 20
//Output: 1
//Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
//Example 2:
//Input: n = 100
//Output: 10
//Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
//Example 3:
//Input: n = 1000
//Output: 262
// 
//Constraints:
//	1 <= n <= 109
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        vector<int> dp(10, 0);
        dp[0] = 1;
        for (int i = 1; i < 10; ++i) {
            dp[i] = dp[i - 1] * 9;
        }
        
        int count = 0;
        int num = n;
        while (num) {
            int digit = num % 10;
            num /= 10;
            if (digit > 0) {
                count += dp[9 - digit];
                if (num == 0) break;
            }
        }
        
        int res = 0;
        num = n;
        while (num) {
            int digit = num % 10;
            num /= 10;
            if (digit > 0) {
                res += dp[9 - digit];
                if (num == 0) break;
            }
        }
        
        return n - res - count;
        
    }
};