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
    int n = strlen(s);
    if (n == 0) return 0;
    
    int maxLen = 0, stack[n];
    stack[0] = -1;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++stack[0]] = i;
        } else {
            if (stack[0] > 0 && s[stack[stack[0]]] == '(') {
                stack[0]--;
                maxLen = max(maxLen, i - stack[stack[0]]);
            } else {
                stack[0] = -1;
            }
        }
    }
    
    return maxLen;
    
}