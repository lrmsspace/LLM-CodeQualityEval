/**https://leetcode.com/problems/valid-parenthesis-string/ */
//Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
//The following rules define a valid string:
//	Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//	Any right parenthesis ')' must have a corresponding left parenthesis '('.
//	Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//	'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
// 
//Example 1:
//Input: s = "()"
//Output: true
//Example 2:
//Input: s = "(*)"
//Output: true
//Example 3:
//Input: s = "(*))"
//Output: true
// 
//Constraints:
//	1 <= s.length <= 100
//	s[i] is '(', ')' or '*'.
class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0, star = 0;
        
        for (char c : s) {
            if (c == '(') {
                ++left;
                ++star;
            } else if (c == ')') {
                --left;
                if (star > 0) --star;
                else ++right;
            } else {
                --star;
            }
            if (left < 0 || right < 0) return false;
        }
        
        return left == 0 && right == 0;
        
    }
};