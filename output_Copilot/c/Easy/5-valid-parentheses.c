/**https://leetcode.com/problems/valid-parentheses/ */
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//An input string is valid if:
//	Open brackets must be closed by the same type of brackets.
//	Open brackets must be closed in the correct order.
//	Every close bracket has a corresponding open bracket of the same type.
// 
//Example 1:
//Input: s = "()"
//Output: true
//Example 2:
//Input: s = "()[]{}"
//Output: true
//Example 3:
//Input: s = "(]"
//Output: false
//Example 4:
//Input: s = "([])"
//Output: true
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of parentheses only '()[]{}'.
bool isValid(char* s) {
    int len = strlen(s);
    if (len % 2 != 0) {
        return false;
    }
    char stack[len];
    int top = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[++top] = s[i];
        } else {
            if (top == -1) {
                return false;
            }
            if (s[i] == ')' && stack[top] != '(') {
                return false;
            }
            if (s[i] == ']' && stack[top] != '[') {
                return false;
            }
            if (s[i] == '}' && stack[top] != '{') {
                return false;
            }
            top--;
        }
    }
    return top == -1;
    
}