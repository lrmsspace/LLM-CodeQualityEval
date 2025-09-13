/**https://leetcode.com/problems/remove-invalid-parentheses/ */
//Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
//Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.
// 
//Example 1:
//Input: s = "()())()"
//Output: ["(())()","()()()"]
//Example 2:
//Input: s = "(a)())()"
//Output: ["(a())()","(a)()()"]
//Example 3:
//Input: s = ")("
//Output: [""]
// 
//Constraints:
//	1 <= s.length <= 25
//	s consists of lowercase English letters and parentheses '(' and ')'.
//	There will be at most 20 parentheses in s.
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0, count = 0;
        vector<string> result;
        
        for (char c : s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                right++;
                if (left < right) {
                    left--;
                } else {
                    count++;
                }
            }
        }
        
        string path = "";
        backtrack(s, 0, 0, left, right, count, path, result);
        
        return result;
        
    }
};