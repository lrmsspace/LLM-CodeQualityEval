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
class Solution {
    public int longestValidParentheses(String s) {
        int maxans = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (isValid(s.substring(i, j + 1))) {
                    maxans = Math.max(maxans, j - i + 1);
                }
            }
        }
        return maxans;
    }
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (stack.isEmpty() || s.charAt(i) == '(') {
                stack.push(s.charAt(i));
            } else if (stack.peek() == '(') {
                stack.pop();
            } else {
                return false;
        }
    } 
    return stack.isEmpty();  
    }
}