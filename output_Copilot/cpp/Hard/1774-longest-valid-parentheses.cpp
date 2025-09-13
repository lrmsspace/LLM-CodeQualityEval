/**https://leetcode.com/problems/longest-valid-parentheses/ */
//Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
// 
//Example 1:
//Input: s = "(()"
//Output: 2
//Explanation: The longest valid parentheses substring is "()".
//Example 2:
//Input: s = ")()())"
//Output: 4
//Explanation: The longest valid parentheses substring is "()()".
//Example 3:
//Input: s = ""
//Output: 0
// 
//Constraints:
//	0 <= s.length <= 3 * 104
//	s[i] is '(', or ')'.
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int maxLen = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxLen = max(maxLen, dp[i]);
            }
        }
        return maxLen;        
    }
};