/**https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/ */
//Given a string s. In one step you can insert any character at any index of the string.
//Return the minimum number of steps to make s palindrome.
//A Palindrome String is one that reads the same backward as well as forward.
// 
//Example 1:
//Input: s = "zzazz"
//Output: 0
//Explanation: The string "zzazz" is already palindrome we do not need any insertions.
//Example 2:
//Input: s = "mbadm"
//Output: 2
//Explanation: String can be "mbdadbm" or "mdbabdm".
//Example 3:
//Input: s = "leetcode"
//Output: 5
//Explanation: Inserting 5 characters the string becomes "leetcodocteel".
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[0][n - 1];
    }
};