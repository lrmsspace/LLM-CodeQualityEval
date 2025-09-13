/**https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/ */
//Given a string s of '(' , ')' and lowercase English characters.
//Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
//Formally, a parentheses string is valid if and only if:
//	It is the empty string, contains only lowercase characters, or
//	It can be written as AB (A concatenated with B), where A and B are valid strings, or
//	It can be written as (A), where A is a valid string.
// 
//Example 1:
//Input: s = "lee(t(c)o)de)"
//Output: "lee(t(c)o)de"
//Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
//Example 2:
//Input: s = "a)b(c)d"
//Output: "ab(c)d"
//Example 3:
//Input: s = "))(("
//Output: ""
//Explanation: An empty string is also valid.
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is either '(' , ')', or lowercase English letter.
char* minRemoveToMakeValid(char* s) {
    int n = strlen(s);
    int stack[n];
    int top = -1;
    char* res = (char*)malloc((n + 1) * sizeof(char));
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else if (s[i] == ')') {
            if (top < 0) {
                continue;
            }
            int j = stack[top--];
            res[idx++] = s[j];
            res[idx++] = s[i];
        } else {
            res[idx++] = s[i];
        }
    }
    res[idx] = '\0';
    return res;
    
}