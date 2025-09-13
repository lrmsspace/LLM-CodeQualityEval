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
        int n = s.length();
        int result = 0;
        vector<int> dp(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty()) {
                    int left = st.top();
                    st.pop();
                    if (st.empty()) {
                        dp[i] = i + 1;
                    } else {
                        dp[i] = i - left + 1 + dp[left - 1];
                    }
                    result = max(result, dp[i]);
                }
            }
        }
        return result;
        
    }
};