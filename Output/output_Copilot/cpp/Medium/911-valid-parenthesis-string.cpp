/**https://leetcode.com/problems/valid-parenthesis-string/ */
//Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
//The following rules define a valid string:
//	Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//	Any right parenthesis ')' must have a corresponding left parenthesis '('.
//	Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//	'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
// 
//Example 1:
//Input: s = "()"
//Output: true
//Example 2:
//Input: s = "(*)"
//Output: true
//Example 3:
//Input: s = "(*))"
//Output: true
// 
//Constraints:
//	1 <= s.length <= 100
//	s[i] is '(', ')' or '*'.
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                dp[i][i] = true;
            }
            if (i < n - 1 && (s[i] == '(' || s[i] == '*') && (s[i + 1] == ')' || s[i + 1] == '*')) {
                dp[i][i + 1] = true;
            }
        }
        for (int size = 2; size < n; size++) {
            for (int i = 0; i + size < n; i++) {
                if (s[i] == '*' && dp[i + 1][i + size]) {
                    dp[i][i + size] = true;
                } else if (s[i] == '(' || s[i] == '*') {
                    for (int k = i + 1; k <= i + size; k++) {
                        if ((s[k] == ')' || s[k] == '*') && (k == i + 1 || dp[i + 1][k - 1]) && (k == i + size || dp[k + 1][i + size])) {
                            dp[i][i + size] = true;
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];        
    }
};