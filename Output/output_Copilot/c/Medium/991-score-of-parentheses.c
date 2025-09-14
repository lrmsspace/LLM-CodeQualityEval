/**https://leetcode.com/problems/score-of-parentheses/ */
//Given a balanced parentheses string s, return the score of the string.
//The score of a balanced parentheses string is based on the following rule:
//	"()" has score 1.
//	AB has score A + B, where A and B are balanced parentheses strings.
//	(A) has score 2 * A, where A is a balanced parentheses string.
// 
//Example 1:
//Input: s = "()"
//Output: 1
//Example 2:
//Input: s = "(())"
//Output: 2
//Example 3:
//Input: s = "()()"
//Output: 2
// 
//Constraints:
//	2 <= s.length <= 50
//	s consists of only '(' and ')'.
//	s is a balanced parentheses string.
int scoreOfParentheses(char* s) {
    int score = 0;
    int len = strlen(s);
    int stack[len];
    int top = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = score;
            score = 0;
        } else {
            score = stack[top--] + (score == 0 ? 1 : 2 * score);
        }
    }
    return score;    
}