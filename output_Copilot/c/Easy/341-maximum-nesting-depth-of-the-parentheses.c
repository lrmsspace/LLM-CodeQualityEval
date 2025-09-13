/**https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/ */
//Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.
// 
//Example 1:
//Input: s = "(1+(2*3)+((8)/4))+1"
//Output: 3
//Explanation:
//Digit 8 is inside of 3 nested parentheses in the string.
//Example 2:
//Input: s = "(1)+((2))+(((3)))"
//Output: 3
//Explanation:
//Digit 3 is inside of 3 nested parentheses in the string.
//Example 3:
//Input: s = "()(())((()()))"
//Output: 3
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
//	It is guaranteed that parentheses expression s is a VPS.
int maxDepth(char* s) {
    int max = 0;
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            count++;
            if (count > max) {
                max = count;
            }
        } else if (s[i] == ')') {
            count--;
        }
    }
    return max;    
}