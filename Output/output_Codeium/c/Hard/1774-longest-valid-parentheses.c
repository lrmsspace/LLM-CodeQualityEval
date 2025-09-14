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
int longestValidParentheses(char* s) {
    int max_len = 0, left = 0, right = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            max_len = fmax(max_len, left + right);
        } else if (right > left) {
            left = right = 0;
        }
    }
    left = right = 0;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            max_len = fmax(max_len, left + right);
        } else if (left > right) {
            left = right = 0;
        }
    }
    return max_len;
}