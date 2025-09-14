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
bool checkValidString(char* s) {
    int left = 0, right = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(') {
            ++left;
            ++right;
        } else if (s[i] == ')') {
            --left;
            ++right;
        } else {
            --right;
            if (right < 0) return false;
            ++left;
        }
        if (left < 0) left = 0;
    }
    return left == 0;
    
}