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
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                dp[i + 1] = dp[i] + 1;
            } else {
                dp[i + 1] = dp[i];
            }
            for (int j = i; j >= 0; j--) {
                if (s[j] == '(' || s[j] == '*') {
                    dp[i + 1] += dp[j];
                } else {
                    dp[i + 1] -= dp[j];
                    break;
                }
            }
            if (dp[i + 1] < 0) {
                return false;
            }
        }
        return dp[n] > 0;      
    }
};