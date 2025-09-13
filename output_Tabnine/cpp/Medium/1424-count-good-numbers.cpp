/**https://leetcode.com/problems/count-good-numbers/ */
//A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
//	For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
//Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
//A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
// 
//Example 1:
//Input: n = 1
//Output: 5
//Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
//Example 2:
//Input: n = 4
//Output: 400
//Example 3:
//Input: n = 50
//Output: 564908303
// 
//Constraints:
//	1 <= n <= 1015
class Solution {
public:
    int countGoodNumbers(long long n) {
        const int MOD = 1e9 + 7;
        long long pow2[n + 1] = {1}, pow3[n + 1] = {1}, pow5[n + 1] = {1};
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
            pow3[i] = (pow3[i - 1] * 3) % MOD;
            pow5[i] = (pow5[i - 1] * 5) % MOD;
        }
        
        long long ans = 0;
        for (int i = 0; i <= n / 2; ++i) {
            ans = (ans + pow2[i] * pow3[n - i] * pow5[i]) % MOD;
        }
        return ans;
        
    }
};