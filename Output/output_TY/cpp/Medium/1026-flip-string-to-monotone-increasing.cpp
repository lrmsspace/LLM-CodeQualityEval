/**https://leetcode.com/problems/flip-string-to-monotone-increasing/ */
//A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).
//You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.
//Return the minimum number of flips to make s monotone increasing.
// 
//Example 1:
//Input: s = "00110"
//Output: 1
//Explanation: We flip the last digit to get 00111.
//Example 2:
//Input: s = "010110"
//Output: 2
//Explanation: We flip to get 011111, or alternatively 000111.
//Example 3:
//Input: s = "00011000"
//Output: 2
//Explanation: We flip to get 00000000.
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is either '0' or '1'.
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int dp[n][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = s[0] == '0' ? 1 : 0;
        dp[0][1] = s[0] == '1' ? 1 : 0;
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][0] + (s[i] == '0' ? 0 : 1);
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + (s[i] =='1' ? 0 : 1);
        }
        return min(dp[n-1][0], dp[n-1][1]);
    }
};