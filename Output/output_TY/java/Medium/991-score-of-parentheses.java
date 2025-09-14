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
class Solution {
    public int scoreOfParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        for (char c : s.toCharArray()) {
            if (c == '(') {
                stack.push(0);
            } else {
                int tmp = stack.pop();
                int val = 0;
                if (tmp > 0) {
                    val = tmp * 2;
                } else {
                    val = 1;
                }
                stack.push(stack.pop() + val);
            }
        }
        return stack.peek();
    }
}