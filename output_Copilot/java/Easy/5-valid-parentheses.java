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
class Solution {
    public boolean isValid(String s) {
        // if the length of the string is odd, then it is not valid
        if (s.length() % 2 != 0) {
            return false;
        }
        // create a stack to store the characters
        Stack<Character> stack = new Stack<>();
        // iterate through the string
        for (char c : s.toCharArray()) {
            // if the character is an opening bracket, then push it into the stack
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                // if the stack is empty, then return false
                if (stack.isEmpty()) {
                    return false;
                }
                // if the character is a closing bracket, then pop the top element from the stack
                char top = stack.pop();
                // if the character is not a closing bracket, then return false
                if (c == ')' && top != '(') {
                    return false;
                }
                if (c == '}' && top != '{') {
                    return false;
                }
                if (c == ']' && top != '[') {
                    return false;
                }
            }
        }
        // if the stack is empty, then return true
        return stack.isEmpty();        
    }
}