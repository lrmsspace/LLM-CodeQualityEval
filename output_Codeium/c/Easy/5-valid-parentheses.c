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

    int stack[10000] = {0}, top = 0;
    for (int i = 0; s[i]; ++i) {
        switch (s[i]) {
            case '(':
                stack[++top] = 1;
                break;
            case ')':
                if (top == 0 || stack[top--] != 1)
                    return false;
                break;
            case '[':
                stack[++top] = 2;
                break;
            case ']':
                if (top == 0 || stack[top--] != 2)
                    return false;
                break;
            case '{':
                stack[++top] = 3;
                break;
            case '}':
                if (top == 0 || stack[top--] != 3)
                    return false;
                break;
        }
    }
    return top == 0;
}