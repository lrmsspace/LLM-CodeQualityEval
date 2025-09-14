/**https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/ */
//You are given a string s that consists of lower case English letters and brackets.
//Reverse the strings in each pair of matching parentheses, starting from the innermost one.
//Your result should not contain any brackets.
// 
//Example 1:
//Input: s = "(abcd)"
//Output: "dcba"
//Example 2:
//Input: s = "(u(love)i)"
//Output: "iloveu"
//Explanation: The substring "love" is reversed first, then the whole string is reversed.
//Example 3:
//Input: s = "(ed(et(oc))el)"
//Output: "leetcode"
//Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
// 
//Constraints:
//	1 <= s.length <= 2000
//	s only contains lower case English characters and parentheses.
//	It is guaranteed that all parentheses are balanced.
char* reverseParentheses(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(sizeof(char) * len);
    int top = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ')') {
            int j = top - 1;
            while (stack[j] != '(') {
                j--;
            }
            int k = j + 1;
            while (k < top) {
                char temp = stack[k];
                stack[k] = stack[j];
                stack[j] = temp;
                k++;
                j--;
            }
            top = j + 1;
        } else {
            stack[top] = s[i];
            top++;
        }
    }
    char* result = (char*)malloc(sizeof(char) * (top + 1));
    strncpy(result, stack, top);
    result[top] = '\0';
    free(stack);
    return result;
}