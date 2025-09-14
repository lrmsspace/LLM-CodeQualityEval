/**https://leetcode.com/problems/count-ways-to-build-good-strings/ */
//Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:
//	Append the character '0' zero times.
//	Append the character '1' one times.
//This can be performed any number of times.
//A good string is a string constructed by the above process having a length between low and high (inclusive).
//Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: low = 3, high = 3, zero = 1, one = 1
//Output: 8
//Explanation: 
//One possible valid good string is "011". 
//It can be constructed as follows: "" -> "0" -> "01" -> "011". 
//All binary strings from "000" to "111" are good strings in this example.
//Example 2:
//Input: low = 2, high = 3, zero = 1, one = 2
//Output: 5
//Explanation: The good strings are "00", "11", "000", "110", and "011".
// 
//Constraints:
//	1 <= low <= high <= 105
//	1 <= zero, one <= low
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(low + 1, vector<int>(high + 1, 0)));
        dp[0][0][0] = 1;
        for (int i = 0; i <= low; ++i) {
            for (int j = 0; j <= high; ++j) {
                for (int k = 0; k < 2; ++k) {
                    if (dp[k][i][j] == 0) continue;
                    for (int l = 0; l < 2; ++l) {
                        if (l == 0 && i + 1 <= low) {
                            dp[0][i + 1][j] = (dp[0][i + 1][j] + dp[k][i][j]) % mod;
                        } else if (l == 1 && j + 1 <= high) {
                            dp[1][i][j + 1] = (dp[1][i][j + 1] + dp[k][i][j]) % mod;
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j <= low; ++j) {
                for (int k = 0; k <= high; ++k) {
                    res = (res + dp[i][j][k]) % mod;
                }
            }
        }
        return res;        
    }
};