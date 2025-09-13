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
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of parentheses only '()[]{}'.
bool isValid(char * s){
       // 定义一个栈和栈顶指针
    char stack[10000];
    int top = -1;

    // 遍历字符串
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        switch (c) {
            case '(':
            case '{':
            case '[':
                // 遇到开括号，入栈
                stack[++top] = c;
                break;
            case ')':
                // 遇到闭括号，检查栈顶是否为对应的开括号
                if (top >= 0 && stack[top] == '(') {
                    top--;
                } else {
                    return false;
                }
                break;
            case '}':
                if (top >= 0 && stack[top] == '{') {
                    top--;
                } else {
                    return false;
                }
                break;
            case ']':
                if (top >= 0 && stack[top] == '[') {
                    top--;
                } else {
                    return false;
                }
                break;
        }
    }

    // 检查栈是否为空
    return top == -1;
}