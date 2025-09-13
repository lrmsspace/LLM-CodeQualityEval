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
    int stack[100005], top = 0;
    int len = strlen(s);
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    memset(result, 0, sizeof(char) * (len + 1));
    int count = 0;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[top++] = i;
        } else if (s[i] == ')') {
            if (top > 0) {
                top--;
            } else {
                count++;
            }
        } else {
            result[count++] = s[i];
        }
    }
    
    for (int i = top - 1; i >= 0; i--) {
        result[count++] = s[stack[i]];
    }

    result[count] = '\0';
    return result;
    
}